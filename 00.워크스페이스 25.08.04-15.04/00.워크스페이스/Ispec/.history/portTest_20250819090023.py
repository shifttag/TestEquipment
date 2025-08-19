import time
import serial
import serial.tools.list_ports

def get_serial_port_stable(baud_rate=115200, timeout=1, wait_ready_s=10):
    ports = serial.tools.list_ports.comports()
    if not ports:
        raise Exception("연결된 시리얼 포트가 없습니다.")
    port_name = ports[0].device
    print(f"Using port: {port_name}")

    ser = serial.Serial(port_name, baud_rate, timeout=timeout)
    start_time = time.time()
    ser.reset_input_buffer()

    # Arduino가 READY 메시지를 보낼 때까지 대기
    while time.time() - start_time < wait_ready_s:
        if ser.in_waiting:
            line = ser.readline().decode('utf-8', errors='ignore').strip()
            if line:
                print(f"Arduino: {line}")
                if "USB ready" in line:
                    return ser
        time.sleep(0.01)

    return ser


def send_command(ser, command, timeout_s=5, max_retries=3):
    """
    - 아두이노에 명령을 보냄
    - 응답 로그 전체를 리스트로 반환
    - 'RESULT:' 로 시작하는 줄은 별도로 결과값으로 리턴
    """
    try_count = 0
    while try_count < max_retries:
        try:
            print(f"Sending: {command}")
            ser.write(f"{command}\n".encode('utf-8'))
            ser.flush()
            time.sleep(0.05)  # Arduino가 데이터를 준비할 시간

            deadline = time.time() + timeout_s
            logs = []        # 전체 로그 저장
            result_value = None  # RESULT: 값 저장

            while time.time() < deadline:
                if ser.in_waiting:
                    line = ser.readline().decode('utf-8', errors='ignore').strip()
                    if line:
                        logs.append(line)        # 전체 로그에 저장
                        print(f"Arduino: {line}") # 화면 출력

                        if line.startswith("RESULT:"):
                            result_value = line.replace("RESULT: ", "")
                else:
                    time.sleep(0.01)  # 반복 체크

            if result_value is not None:
                return result_value, logs  # (명령 결과, 전체 로그)
            else:
                raise Exception("No RESULT line found") 

        except (serial.SerialException, OSError):
            try_count += 1
            print(f"Port lost or no response. Reopening port... (attempt {try_count})")
            ser.close()
            time.sleep(1)
            ser = get_serial_port_stable()

    raise Exception(f"No response from Arduino ({command}) after {max_retries} attempts")


if __name__ == "__main__":
    try:
        ser = get_serial_port_stable()

        # conduction1~5 테스트
        for i in range(1, 6):
            result, logs = send_command(ser, f"conduction{i}")
            print(f"Command Result: {result}")
            print(f"Full Logs: {logs}")

        # short, chassis, capacitance 테스트
        for cmd_name in ["short", "chassis", "capacitance"]:
            result, logs = send_command(ser, cmd_name)
            print(f"Command Result: {result}")
            print(f"Full Logs: {logs}")

    except Exception as e:
        print(f"Error: {e}")
    finally:
        if 'ser' in locals() and ser and ser.is_open:
            ser.close()

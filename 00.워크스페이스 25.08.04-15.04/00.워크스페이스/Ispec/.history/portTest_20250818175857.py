import time
import serial
import serial.tools.list_ports

def get_serial_port_stable(baud_rate=115200, timeout=1, wait_ready_s=10):
    """
    연결 가능한 COM 포트를 자동 탐색하여 반환.
    포트가 없으면 계속 대기하며 재시도.
    Arduino가 READY 메시지 보내면 바로 반환.
    """
    while True:
        ports = serial.tools.list_ports.comports()
        if not ports:
            print("연결된 시리얼 포트 없음, 1초 후 재시도...")
            time.sleep(1)
            continue

        port_name = ports[0].device
        print(f"Trying port: {port_name}")
        try:
            ser = serial.Serial(port_name, baud_rate, timeout=timeout)
            start_time = time.time()
            ser.reset_input_buffer()

            # Arduino READY 대기
            while time.time() - start_time < wait_ready_s:
                while ser.in_waiting:
                    line = ser.readline().decode('utf-8', errors='ignore').strip()
                    if line:
                        print(f"Arduino: {line}")
                        return ser
                time.sleep(0.05)

            # READY 신호 없어도 반환 (명령 전송 가능)
            return ser
        except (serial.SerialException, OSError) as e:
            print(f"포트 열기 실패: {e}, 다음 포트 재시도...")
            time.sleep(1)

def send_command(ser, command, timeout_s=10, retries=3):
    """
    명령 전송 후 RESULT: 메시지 수신 대기
    포트 오류 시 자동 재연결
    """
    attempt = 0
    while attempt < retries:
        try:
            print(f"Sending: {command}")
            ser.write(f"{command}\n".encode('utf-8'))
            ser.flush()
            deadline = time.time() + timeout_s

            while time.time() < deadline:
                while ser.in_waiting:
                    line = ser.readline().decode('utf-8', errors='ignore').strip()
                    if line:
                        print(f"Arduino: {line}")
                        if line.startswith("RESULT:"):
                            return line.replace("RESULT: ", "")
                time.sleep(0.05)

            raise Exception("No response from Arduino")
        except (serial.SerialException, OSError):
            attempt += 1
            print(f"Port lost or no response. Reopening port... (attempt {attempt})")
            try:
                ser.close()
            except:
                pass
            time.sleep(1)
            ser = get_serial_port_stable()

    raise Exception(f"No response from Arduino ({command}) after {retries} attempts")


if __name__ == "__main__":
    ser = None
    try:
        ser = get_serial_port_stable()

        # 테스트 명령
        for i in range(1, 6):
            result = send_command(ser, f"conduction{i}")
            print(f"Command Result: {result}")

        for cmd in ["short", "chassis", "capacitance"]:
            result = send_command(ser, cmd)
            print(f"Command Result: {result}")

    except Exception as e:
        print(f"Error: {e}")
    finally:
        if 'ser' in locals() and ser and ser.is_open:
            ser.close()
            print("Serial port closed.")

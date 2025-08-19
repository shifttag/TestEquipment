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
    
    # Arduino가 준비될 때까지 대기
    while time.time() - start_time < wait_ready_s:
        while ser.in_waiting:
            line = ser.readline().decode('utf-8', errors='ignore').strip()
            if line:
                print(f"Arduino: {line}")
                return ser  # 첫 메시지 받으면 바로 반환
        time.sleep(0.05)
    
    # 기다려도 아무 신호 없으면 그냥 반환(바로 명령 보내기 가능)
    return ser

def send_command(ser, command, timeout_s=5):
    try_count = 0
    while try_count < 3:
        try:
            print(f"Sending: {command}")
            ser.write(f"{command}\n".encode('utf-8'))
            ser.fliush()
            deadline = time.time() + timeout_s
            while time.time() < deadline:
                while ser.in_waiting:
                    line = ser.readline().decode('utf-8', errors='ignore').strip()
                    if line:
                        print(f"Arduino: {line}")
                        if line.startswith("RESULT:"):
                            return line.replace("RESULT: ", "")
                time.sleep(0.05)
            raise Exception("No response")
        except (serial.SerialException, OSError):
            try_count += 1
            print(f"Port lost or no response. Reopening port... (attempt {try_count})")
            ser.close()
            time.sleep(1)
            ser = get_serial_port_stable()
    raise Exception(f"No response from Arduino ({command}) after 3 attempts")

if __name__ == "__main__":
    try:
        ser = get_serial_port_stable()

        # conduction1~5 테스트
        for i in range(1, 6):
            result = send_command(ser, f"conduction{i}")
            print(f"Command Result: {result}")

        # short, chassis, capacitance 테스트
        for cmd in ["short", "chassis", "capacitance"]:
            result = send_command(ser, cmd)
            print(f"Command Result: {result}")

    except Exception as e:
        print(f"Error: {e}")
    finally:
        if ser and ser.is_open:
            ser.close()

import serial
from serial.tools import list_ports
import time

def debug_serial_ports(baud_rate=115200, timeout=1):
    """
    연결 가능한 COM 포트 확인, 점유 여부 체크, 안전하게 열기 시도
    """
    ports = list_ports.comports()
    if not ports:
        print("연결된 시리얼 포트가 없습니다.")
        return None

    print("탐지된 포트 목록:")
    for p in ports:
        print(f"  {p.device} - {p.description}")

    for p in ports:
        port_name = p.device
        print(f"\n[{port_name}] 포트 확인 중...")

        # 점유 여부 확인
        try:
            ser = serial.Serial(port_name, baud_rate, timeout=timeout)
            time.sleep(1)  # 포트 안정화
            print(f"  {port_name} - 포트 열기 성공!")
            ser.close()
        except serial.SerialException as e:
            print(f"  {port_name} - 포트 열기 실패 (점유/접속 불가): {e}")
        except FileNotFoundError as e:
            print(f"  {port_name} - 포트 존재하지 않음: {e}")
        except Exception as e:
            print(f"  {port_name} - 알 수 없는 오류: {e}")

# 사용 예시
debug_serial_ports()


if __name__ == "__main__":
    
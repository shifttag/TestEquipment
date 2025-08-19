import time
import serial

ser = serial.Serial("COM8", 115200, timeout=0.1)

while True:
    print("Bytes in buffer:", ser.in_waiting)
    time.sleep(0.1)

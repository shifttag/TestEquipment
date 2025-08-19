import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque
import time

# 시리얼 설정
ser = serial.Serial("COM8", 115200, timeout=0.1)

# 그래프용 데이터
max_points = 100
loop_dt_data = deque([0]*max_points, maxlen=max_points)
buffer_data = deque([0]*max_points, maxlen=max_points)

fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(8,6))

def animate(frame):
    while ser.in_waiting:
        line = ser.readline().decode('utf-8', errors='ignore').strip()
        if line.startswith("LOOP_DT:"):
            dt = int(line.split(":")[1].strip())
            loop_dt_data.append(dt)
            buffer_data.append(ser.in_waiting)

    ax1.clear()
    ax2.clear()

    ax1.plot(loop_dt_data, label="Arduino LOOP_DT (ms)")
    ax1.set_ylabel("ms")
    ax1.legend()
    ax1.grid(True)

    ax2.plot(buffer_data, label="Python buffer in_waiting (bytes)", color='orange')
    ax2.set_ylabel("Bytes")
    ax2.set_xlabel("Samples")
    ax2.legend()
    ax2.grid(True)

ani = animation.FuncAnimation(fig, animate, interval=100)
plt.tight_layout()
plt.show()

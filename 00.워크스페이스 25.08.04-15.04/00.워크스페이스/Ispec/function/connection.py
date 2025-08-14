import time
import serial
import serial.tools.list_ports
import variable.config as config
from function.event import get_dmm
from function.utils import show_error_modal
import excel
import pandas as pd

# 시리얼 포트 설정

count = 20       # 측정 갯수 설정

def get_serial_port(baud_rate=115200, timeout=1):
    ports = serial.tools.list_ports.comports()
    if not ports:
        raise Exception("연결된 시리얼 포트가 없습니다.")
    port_name = ports[0].device  # 첫 번째 포트 사용
    arduino = serial.Serial(port_name, baud_rate, timeout=timeout)
    time.sleep(2)  # 아두이노와의 연결을 안정화하기 위해 잠시 대기
    return arduino

def notation(val):
    try:
        val = float(val)
    except ValueError:
        return val

    # 범위를 벗어나면 과학적 표기
    if abs(val) >= 1e24 or (0 < abs(val) < 1e-24):
        return f"{val:.2e}"

    prefixes = [
        (1e24, 'Y'),  # yotta
        (1e21, 'Z'),  # zetta
        (1e18, 'E'),  # exa
        (1e15, 'P'),  # peta
        (1e12, 'T'),  # tera
        (1e9,  'G'),  # giga
        (1e6,  'M'),  # mega
        (1e3,  'k'),  # kilo
        (1,    '' ),  # no prefix
        (1e-3, 'm'),  # milli
        (1e-6, 'µ'),  # micro
        (1e-9, 'n'),  # nano
        (1e-12,'p'),  # pico
        (1e-15,'f'),  # femto
        (1e-18,'a'),  # atto
        (1e-21,'z'),  # zepto
        (1e-24,'y'),  # yocto
    ]

    for factor, prefix in prefixes:
        if abs(val) >= factor:
            value = val / factor
            return f"{value:.2f} {prefix}"

    return f"{val:.2e}"  # fallback (실제로 여기까지 안 옴)


    
def measure_conduction_loop(ser, dmm, update_ui_callback=None, collect_data_callback=None):
    for cnt in range(1, count + 2):
        dmm.write("*CLS")
        ser.write(f"conduction{cnt}\n".encode('utf-8'))
        time.sleep(0.1)

        timeout = time.time() + 3
        while not ser.in_waiting and time.time() < timeout:
            time.sleep(0.05)

        if ser.in_waiting:
            conduction = dmm.query("MEAS:RES?").strip()
            formatted_conduction = notation(conduction) + "Ω"
            # ⬇ UI 갱신 콜백 호출
            if update_ui_callback:
                update_ui_callback(cnt - 1, formatted_conduction)
            if collect_data_callback:
                collect_data_callback(cnt - 1, formatted_conduction)

        else:
            raise Exception(f"Arduino 응답 없음 (conduction{cnt} - 측정 실패)")
        
def measure_short_loop(ser, dmm, update_ui_callback=None, collect_data_callback=None):
    for cnt in range(1, count):
        dmm.write("*CLS")
        ser.write(f"short{cnt}\n".encode('utf-8'))
        time.sleep(0.1)

        timeout = time.time() + 3
        while not ser.in_waiting and time.time() < timeout:
            time.sleep(0.05)
        if ser.in_waiting:
            # response = ser.readline().decode('utf-8').strip() # 시리얼 포트에서 응답 디버깅
            short = dmm.query("MEAS:RES?").strip()
            formatted_short = notation(short) + "Ω"
            # formmated_short값을 UI로 전달하는 로직 필요   
            if update_ui_callback:
                update_ui_callback(cnt - 1, formatted_short, mode=3)  # mode=3: 단락검사
            if collect_data_callback:
                collect_data_callback(cnt - 1, formatted_short, mode=3)

        else:
            raise Exception(f"Arduino 응답 없음 (short{cnt} - 측정 실패)")
        
def measure_chassis_loop(ser, dmm, update_ui_callback=None, collect_data_callback=None):
    for cnt in range(1, count + 1):
        dmm.write("*CLS")
        ser.write(f"chassis{cnt}\n".encode('utf-8'))
        time.sleep(0.1)

        timeout = time.time() + 3
        while not ser.in_waiting and time.time() < timeout:
            time.sleep(0.05)
        if ser.in_waiting:
            # response = ser.readline().decode('utf-8').strip() # 시리얼 포트에서 응답 디버깅
            chassis = dmm.query("MEAS:RES?").strip()
            formatted_chassis = notation(chassis) + "Ω"
            # formmated_chassis값을 UI로 전달하는 로직 필요
            if update_ui_callback:
                update_ui_callback(cnt - 1, formatted_chassis, mode=4)  # mode=4: 샤시단락검사
            if collect_data_callback:
                collect_data_callback(cnt - 1, formatted_chassis, mode=4)

        else:
            raise Exception(f"Arduino 응답 없음 (chassis{cnt} - 측정 실패)")
        
def measure_capacitance_loop(ser, dmm, update_ui_callback=None, collect_data_callback=None):
    for cnt in range(1, count + 1):
        dmm.write("*CLS")
        ser.write(f"capacitance{cnt}\n".encode('utf-8'))
        time.sleep(0.1)

        timeout = time.time() + 3
        while not ser.in_waiting and time.time() < timeout:
            time.sleep(0.05)
        if ser.in_waiting:
            # response = ser.readline().decode('utf-8').strip() # 시리얼 포트에서 응답 디버깅
            capacitance = dmm.query("MEAS:CAP?").strip()
            formatted_capacitance = notation(capacitance) + "F"
            # formmated_capacitance값을 UI로 전달하는 로직 필요
            if update_ui_callback:
                update_ui_callback(cnt - 1, formatted_capacitance, mode=5)  # mode=5: 커패시턴스검사
            if collect_data_callback:
                collect_data_callback(cnt - 1, formatted_capacitance, mode=5)

        else:
            raise Exception(f"Arduino 응답 없음 (capacitance{cnt} - 측정 실패)")
        
def measure_conduction_single(ser, dmm, channel, update_ui_callback=None):
    dmm.write("*CLS")
    ser.write(f"conduction{channel}\n".encode('utf-8'))
    time.sleep(0.1)

    timeout = time.time() + 3
    while not ser.in_waiting and time.time() < timeout:
        time.sleep(0.05)

    if ser.in_waiting:
        conduction = dmm.query("MEAS:RES?").strip()
        formatted_conduction = notation(conduction) + "Ω"
        config.channel = None
        if update_ui_callback:
            update_ui_callback(channel - 1, formatted_conduction, mode=2)
        return formatted_conduction
    else:
        raise Exception(f"Arduino 응답 없음 (conduction{channel} - 측정 실패)")

def measure_short_single(ser, dmm, channel, update_ui_callback=None):
        dmm.write("*CLS")
        ser.write(f"short{channel}\n".encode('utf-8'))
        time.sleep(0.1)

        timeout = time.time() + 3
        while not ser.in_waiting and time.time() < timeout:
            time.sleep(0.05)
        if ser.in_waiting:
            # response = ser.readline().decode('utf-8').strip() # 시리얼 포트에서 응답 디버깅
            short = dmm.query("MEAS:RES?").strip()
            formatted_short = notation(short) + "Ω"
            config.channel = None   
            if update_ui_callback:
                update_ui_callback(channel - 1, formatted_short, mode=3)  # mode=3: 단락검사
            return formatted_short
        else:
            raise Exception(f"Arduino 응답 없음 (short{channel} - 측정 실패)")

def measure_chassis_single(ser, dmm, channel, update_ui_callback=None):
        dmm.write("*CLS")
        ser.write(f"chassis{channel}\n".encode('utf-8'))
        time.sleep(0.1)

        timeout = time.time() + 3
        while not ser.in_waiting and time.time() < timeout:
            time.sleep(0.05)
        if ser.in_waiting:
            # response = ser.readline().decode('utf-8').strip() # 시리얼 포트에서 응답 디버깅
            chassis = dmm.query("MEAS:RES?").strip()
            formatted_chassis = notation(chassis) + "Ω"
            config.channel = None
            if update_ui_callback:
                update_ui_callback(channel - 1, formatted_chassis, mode=4)  # mode=4: 샤시단락검사
            return formatted_chassis
        else:
            raise Exception(f"Arduino 응답 없음 (chassis{channel} - 측정 실패)")
        
def measure_capacitance_single(ser, dmm, channel, update_ui_callback=None):
        dmm.write("*CLS")
        ser.write(f"capacitance{channel}\n".encode('utf-8'))
        time.sleep(0.1)

        timeout = time.time() + 3
        while not ser.in_waiting and time.time() < timeout:
            time.sleep(0.05)
        if ser.in_waiting:
            # response = ser.readline().decode('utf-8').strip() # 시리얼 포트에서 응답 디버깅
            capacitance = dmm.query("MEAS:CAP?").strip()
            formatted_capacitance = notation(capacitance) + "F"
            config.channel = None
            if update_ui_callback:
                update_ui_callback(channel - 1, formatted_capacitance, mode=5)  # mode=5: 커패시턴스검사
            return formatted_capacitance
        else:
            raise Exception(f"Arduino 응답 없음 (capacitance{channel} - 측정 실패)")
        
def serialmain(update_voltage_label=None, root=None):
    try:
        ser = get_serial_port()
        dmm = get_dmm()
        ch = getattr(config, 'channel', None)

        if config.mode == 1:
            def collect_data(index, value, mode=None):
                if mode == 3:
                    config.data["단락"].append(value)
                elif mode == 4:
                    config.data["샤시단락"].append(value)
                elif mode == 5:
                    config.data["커패시턴스"].append(value)
                else:
                    config.data["도통"].append(value)
                if update_voltage_label and (mode is None or mode == 1):
                    update_voltage_label(index, value)
            
            # 통합 검사는 무조건 루프 실행 (channel 무시)
            measure_conduction_loop(ser, dmm, update_voltage_label, collect_data)
            measure_short_loop(ser, dmm, update_voltage_label, collect_data)
            measure_chassis_loop(ser, dmm, update_voltage_label, collect_data)
            measure_capacitance_loop(ser, dmm, update_voltage_label, collect_data)
            print({k: len(v) for k, v in config.data.items()})

            excel_path, pdf_path = excel.get_paths()
            template_path = r"C:/Users/agrob/바탕 화면/검사서 템플릿/1. 통합검사.xlsx"
            excel.fill_template(template_path, config.data, config.cell_map, excel_path)
            excel.excel_to_pdf(excel_path, pdf_path)

        elif config.mode == 2:
            # 도통검사
            if ch is not None:
                measure_conduction_single(ser, dmm, ch, update_voltage_label)
            else:
                measure_conduction_loop(ser, dmm, update_voltage_label)

        elif config.mode == 3:
            if ch is not None:
                measure_short_single(ser, dmm, ch, update_voltage_label)
            else:
                measure_short_loop(ser, dmm, update_voltage_label)

        elif config.mode == 4:
            if ch is not None:
                measure_chassis_single(ser, dmm, ch, update_voltage_label)
            else:
                measure_chassis_loop(ser, dmm, update_voltage_label)

        elif config.mode == 5:
            if ch is not None:
                measure_capacitance_single(ser, dmm, ch, update_voltage_label)
            else:
                measure_capacitance_loop(ser, dmm, update_voltage_label)

        else:
            raise Exception("잘못된 모드입니다.")

    except serial.SerialException as e:
        print(f"시리얼 포트 오류: {e}")
        if root:
            show_error_modal(root, f"시리얼 포트 오류:\n{e}")
    except Exception as e:
        print(f"오류 발생: {e}")
        if root:
            show_error_modal(root, f"오류 발생:\n{e}")
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()


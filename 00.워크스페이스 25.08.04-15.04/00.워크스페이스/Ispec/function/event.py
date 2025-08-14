from variable import *
from variable.images import *
import pyvisa
import variable.config as config

# funtion: 종료 버튼 클릭시 프로그램 종료 함수 
def on_close_btn(app):
    app.destroy()

# event handler: 버튼에 마우스 hover시 이벤트 처리 함수
def on_enter(event, communication_icon):
    communication_icon.configure(image=red_image)

def on_leave(event, communication_icon):
    communication_icon.configure(image=green_image)

# function: 버튼 클릭 시 해당 콘텐츠 변경 함수 
def change_content(content, content_label, test_status, app):
    global is_continued
    content_label.configure(text=content)
    if is_continued == 1 or is_continued == 2:
        test_status.configure(text="검사 대기", fg_color="lightblue")
        is_continued = 0

    for frame in subject_frames:
        frame.pack_forget()
            
    if content == "통합 검사":
        config.mode = 1
        for frame in subject_frames:
            frame.pack(side="left", fill = "y", padx=(50, 100), pady=10)
    else:
        for i in range(len(subject_frames)):
            subject_frames[i].pack_forget()
            app.update()
            if content == test_contents[i].cget("text"):
                subject_frames[i].pack(side="left", fill = "y", padx=(50, 100), pady=10)
                config.mode = i + 2
    if hasattr(app, 'reset_voltage_labels'):
        app.reset_voltage_labels()
        
# function : 검사 상태 변경 함수
def change_test_status(event, test_status):
    global is_continued
    if test_status.cget("text") == "검사 대기":
        test_status.configure(text="검사 진행 중", fg_color="yellow")
        is_continued = 1
    elif test_status.cget("text") == "검사 진행 중":
        test_status.configure(text="검사 완료", fg_color="green")
        is_continued = 2
    else:
        test_status.configure(text="검사 대기", fg_color="lightblue")
        is_continued = 3

# function: 검사장비 연결 함수
def get_dmm():
    try:
        rm = pyvisa.ResourceManager()
        dmm = rm.open_resource('USB0::0x2A8D::0x0101::MY64024031::0::INSTR')
        dmm.write("*CLS")
        return dmm
    except Exception as e:
        raise Exception("계측기 연결 실패\n 계측기 연결 상태를 확인해주세요")


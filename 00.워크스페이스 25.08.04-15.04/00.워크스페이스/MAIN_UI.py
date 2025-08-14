import customtkinter as ctk
from PIL import Image
import serial
import time


ctk.set_appearance_mode("light")
ctk.set_default_color_theme("blue")

# state: 상태관리
is_started = False
is_continued = 0
profile_list = []
entry_list = []
menu_items = ["통합검사", "도통검사", "단락검사", "샷시단락검사", "캐패시턴스검사"]
test_content_frames = []
test_contents = []
subject_frames = []
test_items = []


# # 시리얼 포트 설정
# arduino = serial.Serial('COM7', 115200, timeout=1)
# time.sleep(2)  # 아두이노 초기화 대기


def send_command(command):
    arduino.write((command + '\n').encode())
    time.sleep(0.5) 
    response = arduino.readline().decode().strip()
    print("Arduino Response:", response)

# function: 모달 창 열기 함수
def open_modal():
    modal = ctk.CTkToplevel(main_app)
    modal.title("모달 창")
    
    screen_width = main_app.winfo_screenwidth()
    screen_height = main_app.winfo_screenheight()
    modal_width = 300
    modal_height = 400

    x = (screen_width // 2) - (modal_width // 2)
    y = (screen_height // 2) - (modal_height // 2)

    modal.geometry(f"{modal_width}x{modal_height}+{x}+{y}")
    modal.grab_set()  # 모달 효과

    label = ctk.CTkLabel(modal, text="이것은 셋팅창입니다.")
    label.pack(pady=20)

    close_btn = ctk.CTkButton(modal, text="닫기", command=modal.destroy)
    close_btn.pack()


# function: 확인버튼 클릭 함수
def confirm_click(modal):
    profile_list.clear()
    for entry in entry_list:
        profile_list.append(entry.get())
    print("프로필 정보:", profile_list)
    modal.destroy()

# function: 프로필 버튼 클릭 시 모달 창 열기 함수
def open_profile_modal():
    profile_modal = ctk.CTkToplevel(main_app, fg_color="white")
    profile_modal.title("프로필 설정")
    modal_width = 600
    modal_height = 650
    
    screen_width = main_app.winfo_screenwidth()
    screen_height = main_app.winfo_screenheight()
    x = (screen_width // 2) - (modal_width // 2)
    y = (screen_height // 2) - (modal_height // 2)
    profile_modal.geometry(f"{modal_width}x{modal_height}+{x}+{y}")
    profile_modal.grab_set()

    
    blank_frame = ctk.CTkLabel(profile_modal, height=10, text = "프로필 설정", fg_color="white", font=("Arial", 25, "bold"), )
    blank_frame.grid(row=0, column=0, columnspan=4, pady=10, sticky="ew")


    labels = [
        "일련번호", "점검일시",  "점검자 이름",
        "로트번호", "점검장소",  "확인자 이름"
    ]

    for i in range(8):
        profile_modal.columnconfigure(0, weight=1)
        profile_modal.rowconfigure(0, weight=1)
        

    for i in range(len(labels)):

        if i < len(profile_list) and profile_list[i]:
            placeholder = profile_list[i]
        else:
            placeholder = labels[i]

        entry = ctk.CTkEntry(profile_modal, placeholder_text=placeholder, width=400, height=60, font=my_font)
        entry.grid(row=i+1, column=0,padx = 100, columnspan=2, sticky="news")
        entry_list.append(entry)

    blank_frame = ctk.CTkFrame(profile_modal, height=10, fg_color="white")
    blank_frame.grid(row=11, column=0, columnspan=4, pady=10, sticky="ew")

    # 확인 버튼
    confirm_btn = ctk.CTkButton(profile_modal, text="확인", width=400, height=40, command=lambda: confirm_click(profile_modal), font=my_font, fg_color="lightblue", hover=True)
    confirm_btn.grid(row=15, column=0, columnspan=4, padx = 100, pady=20, sticky= "ew")
 

# funciton: 버튼 클릭 시 이미지 변경 함수
# def change_btn():
#     global is_started
#     if (is_started)  :
#         start_btn.configure(image=relax_image)
#     else:
#         start_btn.configure(image=start_image)
#     is_started = not is_started

# funtion: 종료 버튼 클릭시 프로그램 종료 함수 
def close_bth():
    main_app.destroy()

# event handler: 버튼에 마우스 hover시 이벤트 처리 함수
def on_enter(event):
    communication_icon.configure(image=red_image)

def on_leave(event):
    communication_icon.configure(image=green_image)

# function: 버튼 클릭 시 해당 콘텐츠 변경 함수 
def change_content(content):
    global is_continued
    content_label.configure(text=content)
    if is_continued == 1 or is_continued == 2:
        test_status.configure(text="검사 대기", fg_color="lightblue")
        is_continued = 0
            
    if content == "통합검사":
        for frame in subject_frames:
            frame.pack(side="left", fill="y", padx=50, pady=10)
    else:
        for i in range(len(subject_frames)):
            subject_frames[i].pack_forget()
            if content == test_contents[i].cget("text"):
                subject_frames[i].pack(side="left", fill="y", padx=50, pady=10)
        
# function : 검사 상태 변경 함수
def change_test_status(event):
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

# 이미지 로드
start_image = ctk.CTkImage(Image.open("./Ispec/image/start_1.png"), size=(80, 80))
edit_image = ctk.CTkImage(Image.open("./Ispec/image/edit.png"), size=(80, 80))
shutdown_image = ctk.CTkImage(Image.open("./Ispec/image/shutdown_1.png"), size=(150, 150))
relax_image = ctk.CTkImage(Image.open("./Ispec/image/stop.png"), size=(80, 80))
corperation_image = ctk.CTkImage(Image.open("./Ispec/image/corperation.png"), size=(200, 50))
refresh_image = ctk.CTkImage(Image.open("./Ispec/image/refresh_1.png"), size=(30, 30))
red_image = ctk.CTkImage(Image.open("./Ispec/image/red.png"), size=(20, 20))
green_image = ctk.CTkImage(Image.open("./Ispec/image/green.png"), size=(20, 20))
profile_image = ctk.CTkImage(Image.open("./Ispec/image/profile.jpg"), size=(80, 80))

# 메인 윈도우
main_app = ctk.CTk()
main_app.geometry("1060x800")   
main_app.title("아이스펙")

# 폰트 설정
my_font = ("Arial", 18, "bold")


# 상단 메뉴 프레임
top_bar = ctk.CTkFrame(main_app, width= 200, height=300, fg_color="white")
top_bar.pack(side="top", fill="both", expand=False)

underline = ctk.CTkFrame(main_app, height=2, fg_color="lightgray")
underline.pack(fill="x", padx=10)

# 상단 버튼
start_btn = ctk.CTkButton(top_bar, image = start_image, text="", width=80, height=80, fg_color="transparent", command=lambda: send_command("on"), hover=True, border_width=0)
close_btn = ctk.CTkButton(top_bar, image = shutdown_image, text="", width=80, height=80, fg_color="white", command=close_bth , hover=False)
edit_btn = ctk.CTkButton(top_bar, image = edit_image, text="", width=80, height=80, fg_color="white", command=open_modal, hover=False)
profile_btn = ctk.CTkButton(top_bar, text="", width=80, height=80, image= profile_image, fg_color="white", font=my_font, text_color="white", command=open_profile_modal, hover=False)

profile_btn.pack(side="right")
edit_btn.pack(side="right", padx=10)
close_btn.pack(side="right")
start_btn.pack(side="right")

# 상단 회사 아이콘
top_icon = ctk.CTkButton(top_bar, image=corperation_image, text="", width=200, height=50, hover=False, fg_color="white")
top_icon.pack(side="left", padx=10, pady=10)

# 좌측 메뉴 프레임
side_menu = ctk.CTkFrame(main_app, width=800, height=800, fg_color="white")
side_menu.pack(side="left", fill="y")
underline = ctk.CTkFrame(side_menu, width=2, fg_color="lightgray")
underline.pack(side="right",fill="y", padx=10)

for item in menu_items:
    btn = ctk.CTkButton(side_menu, text=item, height=50, width=200, font = my_font, fg_color="lightblue", text_color="black", command=lambda content=item: change_content(content))
    btn.pack(padx=20,pady=25, fill="x")

# 중앙 상단 프레임
# 중앙 컨텐츠 프레임
main_content = ctk.CTkFrame(main_app, fg_color="white")
main_content.pack(expand=True, fill="both")

# 중앙 상단 프레임
main_top_frame = ctk.CTkFrame(main_content, height=50, fg_color="white")
main_top_frame.pack( side="top", fill="x" )

# 새로고침 버튼
refresh_btn = ctk.CTkButton(main_top_frame, text="", image=refresh_image, width=30, height=30, hover=False, fg_color="transparent", border_width=0 )
refresh_btn.pack(side="right")
# 통신 상태 UI
me_communication_status = ctk.CTkLabel(main_top_frame, text="계측기 통신 상태", font=my_font)
me_communication_status.pack(side="right", padx=10, pady=10)
# 통신 상태 아이콘
communication_icon = ctk.CTkButton(main_top_frame, image=green_image, text="", width=20, height=20, hover=False, fg_color="transparent", border_width=0)
communication_icon.pack(side="right")

# 새로고침 버튼
refresh_btn = ctk.CTkButton(main_top_frame, text="", image=refresh_image, width=30, height=30, hover=False, fg_color="transparent", border_width=0 )
refresh_btn.pack(side="right")
# 통신 상태 UI
me_communication_status = ctk.CTkLabel(main_top_frame, text="점검장비 통신 상태", font=my_font)
me_communication_status.pack(side="right", padx=10, pady=10)
# 통신 상태 아이콘
communication_icon = ctk.CTkButton(main_top_frame, image=green_image, text="", width=20, height=20, hover=False, fg_color="transparent", border_width=0)
communication_icon.pack(side="right")

# 중앙 컨텐츠 
content_label = ctk.CTkLabel(main_top_frame, text="검사종류", font=my_font)
content_label.pack(side="left", padx=10, pady=10)

test_status = ctk.CTkLabel(main_top_frame, text="검사 대기", font=my_font, corner_radius=30, fg_color="lightblue")
test_status.pack(side="left", padx=10, pady=10)

underline = ctk.CTkFrame(main_content, height=2, fg_color="lightgray")
underline.pack(side="top", fill="x", expand=False)

for i in range(4):

    # 검사 항목 프레임
    subject_Frame = ctk.CTkFrame(main_content, fg_color="white", border_color="lightgray", border_width=3, corner_radius=20)
    subject_Frame.pack(side="left", fill="y", padx=50, pady=10, expand=False)
    subject_frames.append(subject_Frame)

    test_content = ctk.CTkLabel(subject_Frame, text=menu_items[i+1], font=my_font, fg_color="white")
    test_content.pack(side="top", padx=10, pady=10)
    test_contents.append(test_content)

    test_content_frame = ctk.CTkFrame(subject_Frame, fg_color="lightgray")
    test_content_frame.pack(side="left", expand=False, fill="y", padx=10, pady=10)
    test_content_frames.append(test_content_frame)
    
    for i in range (10):

        test_item = ctk.CTkLabel(test_content_frame, text=f"테스트 내용 {i+1}", font=my_font, fg_color="white")
        test_item.pack(pady=10, padx=10, fill="x")
        test_items.append(test_item)
    
    


communication_icon.bind("<Enter>", on_enter)
communication_icon.bind("<Leave>", on_leave)
test_status.bind("<Button-1>", change_test_status)



main_app.mainloop()

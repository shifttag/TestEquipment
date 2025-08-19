import customtkinter as ctk
from variable import *
from variable.fonts import my_font
from function.connection import *
from function.event import get_dmm
from variable.config import labels

# function: 모달 창 열기 함수
def open_modal(app):
    modal = ctk.CTkToplevel(app)
    modal.title("SETTING")
    
    screen_width = app.winfo_screenwidth()
    screen_height = app.winfo_screenheight()
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


# function: 프로필 버튼 클릭 시 모달 창 열기 함수
def open_profile_modal(app):
    profile_modal = ctk.CTkToplevel(app, fg_color="white")
    profile_modal.title("프로필 설정")
    modal_width = 600
    modal_height = 650
    
    screen_width = app.winfo_screenwidth()
    screen_height = app.winfo_screenheight()
    x = (screen_width // 2) - (modal_width // 2)
    y = (screen_height // 2) - (modal_height // 2)
    profile_modal.geometry(f"{modal_width}x{modal_height}+{x}+{y}")
    profile_modal.grab_set()

    
    blank_frame = ctk.CTkLabel(profile_modal, height=10, text = "프로필 설정", fg_color="white", font=("Arial", 25, "bold"), )
    blank_frame.grid(row=0, column=0, columnspan=4, pady=10, sticky="ew")

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

    # function: 확인버튼 클릭 함수
    def confirm_click(modal):
        profile_list.clear()
        for entry in entry_list:
            profile_list.append(entry.get())
        print("프로필 정보:", profile_list)
        modal.destroy()

    # 확인 버튼
    confirm_btn = ctk.CTkButton(profile_modal, text="확인", width=400, height=40, command=lambda: confirm_click(profile_modal), font=my_font, fg_color="lightblue", hover=True)
    confirm_btn.grid(row=15, column=0, columnspan=4, padx = 100, pady=20, sticky= "ew")

def show_error_modal(root, message):
    error_modal = ctk.CTkToplevel(root)
    error_modal.title("오류 발생")
    error_modal.grab_set()

    modal_width = 400
    modal_height = 200

    # 화면 크기 (정중앙 계산용)
    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()

    x = (screen_width // 2) - (modal_width // 2)
    y = (screen_height // 2) - (modal_height // 2)

    error_modal.geometry(f"{modal_width}x{modal_height}+{x}+{y}")

    label = ctk.CTkLabel(error_modal, text=message, text_color="red", wraplength=350, font=("Arial", 14))
    label.pack(padx=20, pady=40)

    ok_btn = ctk.CTkButton(error_modal, text="확인", command=error_modal.destroy)
    ok_btn.pack(pady=10)

def open_single_measurement_modal(app):
    modal = ctk.CTkToplevel(app)
    modal.title("단일 측정 설정")
    modal.geometry("300x300")
    modal.grab_set()  # 모달화

    ctk.CTkLabel(modal, text="모드 선택", anchor="w").pack(padx=20, pady=(20, 5), fill="x")
    mode_dict = {
    "도통검사": 2,
    "단락검사": 3,
    "샤시단락검사": 4,
    "커패시턴스검사": 5
    }
    mode_combobox = ctk.CTkComboBox(modal, values=list(mode_dict.keys()))
    mode_combobox.set("도통검사")  # 기본값
    mode_combobox.pack(padx=20, pady=5, fill="x")

    ctk.CTkLabel(modal, text="채널 선택 (1~20)", anchor="w").pack(padx=20, pady=(20, 5), fill="x")
    channel_combobox = ctk.CTkComboBox(modal, values=[str(i) for i in range(1, 21)])
    channel_combobox.set("1")
    channel_combobox.pack(padx=20, pady=5, fill="x")

    result_label = ctk.CTkLabel(modal, text="결과: 측정 전")
    result_label.pack(padx=20, pady=15)

    def perform_single_measurement():
        try:
            ser = get_serial_port_safe()
            dmm = get_dmm()
            selected_text = mode_combobox.get()
            selected_mode = mode_dict[selected_text]
            selected_channel = int(channel_combobox.get())

            # 측정 실행
            if selected_mode == 2:
                result = measure_conduction_single(ser, dmm, selected_channel)
            elif selected_mode == 3:
                result = measure_short_single(ser, dmm, selected_channel)
            elif selected_mode == 4:
                result = measure_chassis_single(ser, dmm, selected_channel)
            elif selected_mode == 5:
                result = measure_capacitance_single(ser, dmm, selected_channel)
            else:
                result = "지원하지 않는 모드"

            result_label.configure(text=f"결과: {result}")

        except Exception as e:
            result_label.configure(text=f"오류: {e}")
        finally:
            if 'ser' in locals() and ser.is_open:
                ser.close()

    measure_btn = ctk.CTkButton(modal, text="측정 실행", command=perform_single_measurement)
    measure_btn.pack(pady=10)

    # 닫기 버튼
    close_btn = ctk.CTkButton(modal, text="닫기", command=modal.destroy)
    close_btn.pack(pady=10)
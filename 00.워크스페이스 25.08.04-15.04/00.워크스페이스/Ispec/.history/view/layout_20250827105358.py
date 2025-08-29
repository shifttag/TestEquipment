import customtkinter as ctk
from function.event import *
from function.modal import *
from function.connection import serialmain
import threading

class MainUI:
    def __init__(self):
        self.main_app = ctk.CTk()
        screen_width = self.main_app.winfo_screenwidth()
        screen_height = self.main_app.winfo_screenheight()
        self.main_app.geometry(f"{screen_width}x{screen_height}+0+0")
        self.main_app.title("아이스펙")
        self.voltage_labels = [[] for _ in range(4)]  # 각 항목별로 20개씩 라벨 저장
        self.build_ui()

    def build_ui(self):

        # 상단 메뉴 프레임
        top_bar = ctk.CTkFrame(self.main_app, width= 200, height=300, fg_color="white")
        top_bar.pack(side="top", fill="both", expand=False)

        underline = ctk.CTkFrame(self.main_app, height=2, fg_color="lightgray")
        underline.pack(fill="x", padx=10)

        # 상단 버튼
        test_btn = ctk.CTkButton(top_bar, image=test_image, text = "", width=80, height=80, fg_color="white", command=lambda: open_single_measurement_modal(self.main_app))
        start_btn = ctk.CTkButton(top_bar, image=start_image, text="", width=80, height=80, fg_color="transparent", border_width=0, hover=True, command=lambda: threading.Thread(target=serialmain, args=(self.update_voltage_label, self.main_app)).start())
        close_btn = ctk.CTkButton(top_bar, image = shutdown_image, text="", width=80, height=80, fg_color="white", command=lambda: on_close_btn(self.main_app) , hover=True)
        edit_btn = ctk.CTkButton(top_bar, image = edit_image, text="", width=80, height=80, fg_color="white", command=lambda: open_modal(self.main_app), hover=True)
        profile_btn = ctk.CTkButton(top_bar, text="", width=80, height=80, image= profile_image, fg_color="white", font=my_font, text_color="white", command=lambda: open_profile_modal(self.main_app), hover=True)

        
        profile_btn.pack(side="right")
        edit_btn.pack(side="right", padx=10)
        close_btn.pack(side="right")
        start_btn.pack(side="right")
        test_btn.pack(side="right", padx=10)

            # 상단 회사 아이콘
        top_icon = ctk.CTkButton(top_bar, image=corperation_image, text="", width=200, height=50, hover=False, fg_color="white")
        top_icon.pack(side="left", padx=10, pady=10)

        # 좌측 메뉴 프레임
        side_menu = ctk.CTkFrame(self.main_app, width=800, height=800, fg_color="white")
        side_menu.pack(side="left", fill="y")
        underline = ctk.CTkFrame(side_menu, width=2, fg_color="lightgray")
        underline.pack(side="right",fill="y", padx=10)

        for item in menu_items:
            btn = ctk.CTkButton(side_menu, text=item, height=50, width=200, font = my_font, fg_color="lightblue", text_color="black", command=lambda content=item: self.on_change_content(content, content_label, test_status), hover=True)
            btn.pack(padx=20,pady=25, fill="x")

        # 중앙 상단 프레임
        # 중앙 컨텐츠 프레임
        main_content = ctk.CTkFrame(self.main_app, fg_color="white")
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
        content_label.pack_propagate(False)

        test_status = ctk.CTkLabel(main_top_frame, text="검사 대기", font=my_font, corner_radius=30, fg_color="lightblue")
        test_status.pack(side="left", padx=10, pady=10)

        underline = ctk.CTkFrame(main_content, height=2, fg_color="lightgray")
        underline.pack(side="top", fill="x", expand=False)


        for i in range(4):
        
            # 검사 항목 프레임
            subject_Frame = ctk.CTkFrame(main_content, fg_color="white", width = 200, border_color="lightgray", border_width=3, corner_radius=20)
            subject_Frame.pack(side="left", fill = "y", padx=(50, 100), pady=10)
            subject_Frame.pack_propagate(False)
            subject_frames.append(subject_Frame)

            test_content = ctk.CTkLabel(subject_Frame, text=menu_items[i+1], font=my_font, fg_color="white")
            test_content.pack(side="top", padx=10, pady=(10, 5))
            test_contents.append(test_content)

            test_content_frame = ctk.CTkFrame(subject_Frame, fg_color="lightgray", width=100)
            test_content_frame.pack(side="left", expand=True, fill="both", padx=10, pady=10)
            test_content_frames.append(test_content_frame)
            
            voltage_labels_per_item = []
            for _ in range(21):
                label = ctk.CTkLabel(test_content_frame, text="대기", font=my_font, fg_color="white")
                label.pack(pady=5, padx=10, fill="x")
                voltage_labels_per_item.append(label)
                self.voltage_labels[i] = voltage_labels_per_item

        communication_icon.bind("<Enter>", lambda event, icon=communication_icon: on_enter(event, icon))
        communication_icon.bind("<Leave>", lambda event, icon=communication_icon: on_leave(event, icon))
        test_status.bind("<Button-1>",  lambda event, status=test_status: change_test_status(event, status))

    def update_voltage_label(self, index, value, mode=2):
    # 임시로 첫 번째 항목만 사용한다고 가정 (self.voltage_labels[0])
        if 0 <= index < 21:
        # mode 인덱스는 voltage_labels 리스트에서 0부터 3까지 할당되어 있으므로, mode-2를 인덱스로 사용
            idx = mode - 2
            if 0 <= idx < len(self.voltage_labels):
                self.voltage_labels[idx][index].configure(text=value)

    # 모드 변경 시 대기로 초기화
    def on_change_content(self, content, content_label, test_status):
        change_content(content, content_label, test_status, self.main_app)  # 여기서는 root 윈도우 전달
        # voltage_labels 초기화
        for category_labels in self.voltage_labels:
            for label in category_labels:
                label.configure(text="대기")
                
    def run(self):
        self.main_app.mainloop()


    def check(self, value):
        value = int(self.voltage_labels[idx][index].trim().remove("Ω"))

        if(value > 0.01 or value <0.99):
            
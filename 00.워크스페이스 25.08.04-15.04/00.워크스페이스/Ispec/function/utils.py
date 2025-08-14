import customtkinter as ctk

def show_error_modal(root, message):
    error_modal = ctk.CTkToplevel(root)
    error_modal.title("오류 발생")
    error_modal.grab_set()

    modal_width = 400
    modal_height = 200

    # 화면 정중앙 위치 계산
    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()
    x = (screen_width // 2) - (modal_width // 2)
    y = (screen_height // 2) - (modal_height // 2)
    error_modal.geometry(f"{modal_width}x{modal_height}+{x}+{y}")

    label = ctk.CTkLabel(error_modal, text=message, text_color="red", wraplength=350, font=("Arial", 14))
    label.pack(padx=20, pady=40)

    ok_btn = ctk.CTkButton(error_modal, text="확인", command=error_modal.destroy)
    ok_btn.pack(pady=10)

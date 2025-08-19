import customtkinter as ctk

# 전역 변수
from variable.images import *            
from variable.fonts import my_font       
from variable import *                  

# 함수, 이벤트 핸들러
from function.event import *          
from function.modal import *            
from function.connection import *      


from view.layout import MainUI           


if __name__ == "__main__":

    ctk.set_appearance_mode("system")  
    ctk.set_default_color_theme("blue")

    app = MainUI()
    
    app.run()            

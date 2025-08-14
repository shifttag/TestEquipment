from customtkinter import CTkImage
from PIL import Image
import sys
import os

if getattr(sys, 'frozen', False):
    base_path = sys._MEIPASS
else:
    base_path = os.path.abspath(".")

def resource_path(relative_path):
    return os.path.join(base_path, relative_path)

start_image = CTkImage(Image.open(resource_path("image/play.png")), size=(60, 60))
edit_image = CTkImage(Image.open(resource_path("image/setting.png")), size=(60, 60))
shutdown_image = CTkImage(Image.open(resource_path("image/pause.png")), size=(80, 80))
relax_image = CTkImage(Image.open(resource_path("image/stop.png")), size=(80, 80))
corperation_image = CTkImage(Image.open(resource_path("image/corperation.png")), size=(200, 50))
refresh_image = CTkImage(Image.open(resource_path("image/refresh_1.png")), size=(30, 30))
red_image = CTkImage(Image.open(resource_path("image/red.png")), size=(20, 20))
green_image = CTkImage(Image.open(resource_path("image/green.png")), size=(20, 20))
profile_image = CTkImage(Image.open(resource_path("image/profile.png")), size=(60, 60))
test_image = CTkImage(Image.open(resource_path("image/test.png")), size=(60, 60))
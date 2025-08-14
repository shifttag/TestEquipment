@echo off
cd /d "%~dp0"
"C:\Users\agrob\AppData\Local\Programs\Python\Python313\python.exe" -m PyInstaller --clean main.spec -y
pause

# -*- mode: python ; coding: utf-8 -*-

a = Analysis(
    ['main.py'],
    pathex=[],
    binaries=[],
    datas=[
    ('image\\play.png', 'image'),
    ('image\\setting.png', 'image'),
    ('image\\pause.png', 'image'),
    ('image\\stop.png', 'image'),
    ('image\\corperation.png', 'image'),
    ('image\\refresh_1.png', 'image'),
    ('image\\red.png', 'image'),
    ('image\\green.png', 'image'),
    ('image\\profile.png', 'image'),
    ('image\\test.png', 'image'),
],
    hiddenimports=['tkinter', 'customtkinter'],
    hookspath=[],
    runtime_hooks=[],
    excludes=[],
    noarchive=False,
    optimize=0,
)

pyz = PYZ(a.pure)

exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.datas,
    name='main',
    debug=False,
    strip=False,
    upx=True,
    console=False,  # 콘솔 없이 GUI용으로 실행
)

coll = COLLECT(
    exe,
    a.binaries,
    a.datas,
    strip=False,
    upx=True,
    name='main',
)

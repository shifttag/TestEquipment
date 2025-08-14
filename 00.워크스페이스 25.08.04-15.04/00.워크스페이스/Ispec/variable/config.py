mode = 1
channel = None

data = {
    "채널": list(range(1, 21)),
    "도통": [],
    "단락": [],
    "샤시단락": [],
    "커패시턴스": []
}
cell_map = {
    "도통": [f"G{row}" for row in range(11, 32)],         # G11~G31
    "단락": [f"P{row}" for row in range(11, 30)],          # P11~P29
    "샤시단락": [f"W{row}" for row in range(11, 31)],      # W11~W30
    "커패시턴스": [f"AE{row}" for row in range(11, 31)]    # AE11~AE30
}

labels = [
    "일련번호", "점검일시", "점검자 이름", "로트번호", "점검장소", "확인자 이름"
]

profile_map = {
    "일련번호": "W2",
    "점검일시": "F3",
    "점검자 이름": "I5",
    "로트번호": "AD2",
    "점검장소": "W3",
    "확인자 이름": "Z5"
}
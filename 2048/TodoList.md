# 기능 체크리스트

### 구현된 것

### Prototype

- [x]  moveUp / moveDown / moveLeft / moveRight
- [x]  initBoard
- [x]  printBoard
- [x]  addTile
- [x]  isGameOver
- [x]  addTile
- [x]  꽉찼을 때 가로, 세로 이동 안되는 문제 수정하기

---

### Alpha Version

- [x]  2048 만들면 게임 이겼다고 표시하기
- [x]  전체 로직 체크하기
- [x]  Game isGameWin : 2048 있는지 체크하기
    
    
- [x]  Game move 함수들에서 추가된 점수 리턴받기 ← Score showScore 점수 표시
    
    
- [x]  Board addTile 점수 바뀌었는지 체크하고 실행하기 ← 0 체크해서 랜덤한 위치 생성하기
- [x]  UI printMoveScore : 숫자 몇 점씩 더해지는지 표시하기
- [x]  UI printPlayerScore : 플레이어 점수 표시하기
- [x]  Board initBoard : playerScore 리턴하기 0으로 바꾸기
- [x]  Score getBestScore 베스트 스코어

---

- [x]  Double Buffer로 깜박거림 없애기
- [x]  UI 제목 이공사팔 만든거 넣기
- [x]  UI 형태 잡기
- [x]  추천 방향키 되도록 만들기
- [x]  Double Buffer 써서 출력 부분 마저 만들기
- [x]  Score writeScore 랭킹 텍스트 파일로 저장하기 - 최고 점수 내림차순
- [x]  Sound EFFECT

---

### 구현할 것

---

- [ ]  Tile color : 1,2,3,4,5,6,7,8,9,10,11
- [ ]  Sound BGM
- [ ]  Init setLevel 메뉴에서 난이도 조절 : 판 크기 6 / 5 / 4 : easy / normal / hard

---

### 이서영

- moveUp / moveDown / moveLeft / moveRight
- initBoard
- printBoard
- addTile
- isGameOver
- addTile
- 꽉찼을 때 가로, 세로 이동 안되는 문제 수정하기
- 2048 만들면 게임 이겼다고 표시하기
- 전체 로직 체크하기
- Game move 함수들에서 추가된 점수 리턴받기 ← Score showScore 점수 표시
- Score getBestScore 베스트 스코어
- 추천 방향키 되도록 만들기
- Sound EFFECT

---

### 김주영

- moveUp / moveDown / moveLeft / moveRight
- 꽉찼을 때 가로, 세로 이동 안되는 문제 수정하기
- 전체 로직 체크하기
- Double Buffer로 깜박거림 없애기
- UI 제목 이공사팔 만든거 넣기
- UI 형태 잡기
- Double Buffer 써서 출력 부분 마저 만들기
- Score writeScore 랭킹 텍스트 파일로 저장하기 - 최고 점수 내림차순

---

---

### 이서영

- [ ]  Score showScore 점수 표시
- [ ]  Score getBestScore 베스트 스코어
- [ ]  Score writeScore 랭킹 텍스트 파일로 저장하기

- [ ]  Sound BGM / EFFECT

- [ ]  Tile color : 1,2,3,4,5,6,7,8,9,10,11
- [ ]  Tile isTileChaged : 랜덤생성, 합쳐져서 만들어진 타일 생성될 때 커지는 애니메이션 넣기

- [ ]  Game isGameWin : 2048 있는지 체크하기

- [ ]  Score showAddScore : 숫자 몇 점씩 더해지는지 표시하기

- [ ]  Init setLevel 메뉴에서 난이도 조절 : 판 크기 6 / 5 / 4 : easy / normal / hard

- [ ]  Input 키 입력받은 상태 매핑하기
- [ ]  Input restartGame : [ESC] || [Q] || [q]
- [ ]  Input move : [LEFT] [RIGHT] [UP] [DOWN]

- [ ]  Double Buffer로 깜박거림 없애기

---

### 김주영

<UI>

- [ ]  현재 스코어
- [ ]  최고 스코어

<타일 이동 효과>

- [ ]  타일 이동 애니매이션
- [ ]  이동 사운드
- [ ]  n 배수마다 색깔 추가

<랭킹 기능> 

- [ ]  게임이 끝난 후 이름 입력
- [ ]  랭킹 리스트 화면 출력
- [ ]  게임 오버 화면

<기타>

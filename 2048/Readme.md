# 기능 체크리스트

### 구현된 것

- [x]  moveUp / moveDown / moveLeft / moveRight
- [x]  initBoard
- [x]  printBoard
- [x]  addTile
- [x]  isGameOver
- [x]  addTile
- [x]  꽉찼을 때 가로, 세로 이동 안되는 문제 수정하기
- [x]  2048 만들면 게임 이겼다고 표시하기
- [x]  전체 로직 체크하기
- [x]  Game isGameWin : 2048 있는지 체크하기
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9d098552-7049-43b3-aafd-e75ef2466f42/Untitled.png)
    
- [x]  Game move 함수들에서 추가된 점수 리턴받기 ← Score showScore 점수 표시
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1a870092-1764-407d-814a-e3b3430cbc6f/Untitled.png)
    
- [x]  Board addTile 점수 바뀌었는지 체크하고 실행하기 ← 0 체크해서 랜덤한 위치 생성하기
- [x]  UI printMoveScore : 숫자 몇 점씩 더해지는지 표시하기
- [x]  UI printPlayerScore : 플레이어 점수 표시하기
- [x]  Board initBoard : playerScore 리턴하기 0으로 바꾸기
- [x]  Score getBestScore 베스트 스코어
- [x]  Double Buffer로 깜박거림 없애기
- [x]  추천 방향키 되도록 만들기
- [x]  이공사팔 만든거 넣기
- [x]  UI 형태 잡기
- [x]  Double Buffer 써서 출력 부분 마저 만들기
- [x]  Sound EFFECT
- [ ]  입력 로직 부분 파일 더 만들어서 함수로 부르기

---

### 구현할 것

---

- [ ]  

---

- [ ]  Score writeScore 랭킹 텍스트 파일로 저장하기 - 최고 점수 내림차순
    - 게임 시작 시 랭킹 출력
        - 파일을 연다
        - 파일을 읽는다
        - 파을을 닫는다
        - 배열에 정렬해서 저장한다
        - 화면에 배열 출력한다
    -게임이 끝나고
        - 파일을 연다
        - 현제 스코어를 쓴다
        - 파일을 닫는다

- [ ]  Tile color : 1,2,3,4,5,6,7,8,9,10,11

- [ ]  Sound BGM

~- [ ]  Init setLevel 메뉴에서 난이도 조절 : 판 크기 6 / 5 / 4 : easy / normal / hard~

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

참고 링크<네이버 블로그 - C언어로 게임만드는 데 필요한 모든 상식>

[메인 화면, 메뉴 선택](https://blog.naver.com/PostView.nhn?blogId=ifthe1201&logNo=221056588399)

[세이브,로드 / 게임 오버](https://blog.naver.com/PostView.naver?blogId=ifthe1201&logNo=221057260605&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView)

[음악, 랭킹 등](https://blog.naver.com/PostView.naver?blogId=ifthe1201&logNo=221057773844&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView)
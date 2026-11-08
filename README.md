# LIG SSEN Algorithm Study 5th

The SSEN Embedded SW LIG D&A 5기 코딩테스트 스터디 저장소입니다.
매주 같은 문제를 풀고, Pull Request로 서로의 코드를 리뷰합니다.

## 운영 규칙

| 항목 | 내용 |
| --- | --- |
| 문제 | 매주 3문제 (주차별 이슈에 공지) |
| 풀이 제출 | 일요일 15:00까지 PR 생성 |
| 리뷰 | 일요일 23:59까지 담당 PR 2개 리뷰 |
| 머지 | 승인 2개를 받으면 작성자가 직접 Squash and merge |
| 언어 | C++ |
| 주간 모임 | 매주 월요일 수업 후, GPT가 뽑은 사람이 풀이를 설명 |

못 푼 문제가 있어도 시도한 코드와 막힌 지점을 적어 PR을 올려 주세요. 그런 PR에서 가장 많이 배웁니다.

AI에게 설명을 듣고 풀었다면 이해한 내용을 자기 말로 풀어서 주석에 남깁니다. 자세한 내용은 [CONTRIBUTING.md](CONTRIBUTING.md#주석-작성)를 참고하세요.

## 폴더 구조

```text
week01/
├── PGS12906/
│   ├── euichan.cpp
│   └── jaehwan.cpp
└── PGS42576/
    └── jihoon.cpp
```

- 문제 폴더 이름은 매주 안의찬님이 정해 주는 이름을 그대로 씁니다.
- 풀이 파일 이름은 `<멤버 표의 파일 이름>.cpp` 형식으로 씁니다.
- 각자 자기 이름의 파일만 수정하므로 다른 사람과 충돌이 나지 않습니다.
- 예시는 [week00/BOJ1000/example.cpp](week00/BOJ1000/example.cpp)를 참고하세요.

## 참여 방법

제출과 리뷰 절차는 [CONTRIBUTING.md](CONTRIBUTING.md)에 있습니다.

## 멤버

| 번호 | 이름 | 파일 이름 | GitHub |
| --- | --- | --- | --- |
| 1 | 김재환 | jaehwan | [<img src="https://github.com/jh-stpn.png?size=40" width="40" height="40" alt="jh-stpn"> jh-stpn](https://github.com/jh-stpn) |
| 2 | 김주형 | juhyeong | [<img src="https://github.com/kimjoohyungsd.png?size=40" width="40" height="40" alt="kimjoohyungsd"> kimjoohyungsd](https://github.com/kimjoohyungsd) |
| 3 | 박제영 | jeyoung | [<img src="https://github.com/jae0000.png?size=40" width="40" height="40" alt="jae0000"> jae0000](https://github.com/jae0000) |
| 4 | 백웅일 | ulil | [<img src="https://github.com/callbyreference-github.png?size=40" width="40" height="40" alt="callbyreference-github"> callbyreference-github](https://github.com/callbyreference-github) |
| 5 | 서의진 | uijin | [<img src="https://github.com/se71nny.png?size=40" width="40" height="40" alt="se71nny"> se71nny](https://github.com/se71nny) |
| 6 | 안의찬 | euichan | [<img src="https://github.com/Hanyangsaja.png?size=40" width="40" height="40" alt="Hanyangsaja"> Hanyangsaja](https://github.com/Hanyangsaja) |
| 7 | 이지훈 | jihoon | [<img src="https://github.com/codehooni.png?size=40" width="40" height="40" alt="codehooni"> codehooni](https://github.com/codehooni) |
| 8 | 전진성 | jinseong | [<img src="https://github.com/notCoderJ.png?size=40" width="40" height="40" alt="notCoderJ"> notCoderJ](https://github.com/notCoderJ) |
| 9 | 주윤빈 | yunbin | [<img src="https://github.com/dkdltm221.png?size=40" width="40" height="40" alt="dkdltm221"> dkdltm221](https://github.com/dkdltm221) |
| 10 | 김재희 | jaehee | [<img src="https://github.com/jaeee320.png?size=40" width="40" height="40" alt="jaeee320"> jaeee320](https://github.com/jaeee320) |
| 11 | 최원준 | wonjun | [<img src="https://github.com/Dreaming1024155.png?size=40" width="40" height="40" alt="Dreaming1024155"> Dreaming1024155](https://github.com/Dreaming1024155) |

## 리뷰어 배정

멤버 표를 번호 순서대로 원형으로 세우고, 내 번호에서 **k칸 뒤**와 **2k칸 뒤** 사람이 이번 주 내 리뷰어입니다. 11번 다음은 다시 1번입니다.

- k는 주차 번호입니다. 11주차부터는 10을 뺀 값(11주차는 1, 12주차는 2)을 씁니다.
- 번호 i인 멤버의 리뷰어: `(i - 1 + k) % 11 + 1`번, `(i - 1 + 2k) % 11 + 1`번

모두가 리뷰어 2명을 받고, 담당 PR도 정확히 2개씩 돌아갑니다.

| 주차 | 예시 |
| --- | --- |
| 1주차 (k = 1) | 7번 이지훈 → 8번 전진성, 9번 주윤빈 / 11번 최원준 → 1번 김재환, 2번 김주형 |
| 2주차 (k = 2) | 7번 이지훈 → 9번 주윤빈, 11번 최원준 / 11번 최원준 → 2번 김주형, 4번 백웅일 |

## 주의 사항

- 문제 지문은 저작권이 있으니 복사하지 말고 링크만 남깁니다.
- 실제 기업 코딩테스트 문제를 복원해서 올리지 않습니다.

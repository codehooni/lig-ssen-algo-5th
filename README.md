# LIG SSEN Algorithm Study 5th

The SSEN Embedded SW LIG D&A 5기 코딩테스트 스터디 저장소입니다.
매주 같은 문제를 풀고, Pull Request로 서로의 코드를 리뷰합니다.

## 운영 규칙

| 항목 | 내용 |
| --- | --- |
| 문제 | 매주 3문제 (주차별 이슈에 공지) |
| 풀이 제출 | 일요일 12:00까지 PR 생성 |
| 리뷰 | 일요일 23:59까지 담당 PR 2개 리뷰 |
| 머지 | 승인 2개를 받으면 작성자가 직접 Squash and merge |
| 언어 | C++ |
| 주간 모임 | 매주 월요일 수업 후, GPT가 뽑은 사람이 풀이를 설명 |

못 푼 문제가 있어도 시도한 코드와 막힌 지점을 적어 PR을 올려 주세요. 그런 PR에서 가장 많이 배웁니다.

## 폴더 구조

```text
week01/
├── BOJ1260/
│   ├── uichan.cpp
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

## 리뷰 담당자 정하기

아래 멤버 표의 번호로 담당자를 정합니다. 매주 조합이 바뀌고, 모두가 매주 2개의 PR을 리뷰합니다.

```text
offset = (주차 - 1) % 9 + 1

내 PR의 리뷰어 = 내 번호 + offset, 내 번호 + offset + 1
(11을 넘으면 11을 뺍니다)
```

예를 들어 3주차는 offset이 3이므로, 1번의 리뷰어는 4번과 5번이고 11번의 리뷰어는 3번과 4번입니다.

인원이 바뀌면 11을 현재 인원 N으로, 9를 N - 2로 바꿔서 계산합니다.

## 멤버

| 번호 | 이름 | 파일 이름 | GitHub |
| --- | --- | --- | --- |
| 1 | 김재환 | jaehwan | jh-stpn |
| 2 | 김주형 | juhyeong | kimjoohyungsd |
| 3 | 박제영 | jeyoung | |
| 4 | 백울일 | ulil | |
| 5 | 서의진 | uijin | |
| 6 | 안의찬 | euichan | Hanyangsaja |
| 7 | 이지훈 | jihoon | |
| 8 | 전진성 | jinseong | notCoderJ |
| 9 | 주윤빈 | yunbin | dkdltm221 |
| 10 | 김재희 | jaehee | |
| 11 | 최원준 | wonjun | |

## 주의 사항

- 문제 지문은 저작권이 있으니 복사하지 말고 링크만 남깁니다.
- 실제 기업 코딩테스트 문제를 복원해서 올리지 않습니다.

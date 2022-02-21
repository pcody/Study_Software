## git 시작하기

- 새로운 로컬 저장소를 만들어 사용하는 경우

  로컬 디렉토리를 git 저장소로 만든다. (.git 디렉토리가 생성된다.)

  - git init

  원격 저장소를 등록한다.

  - git remote add [저장소이름] [URL]
  - URL : git://github.com/~~

  원격 저장소 확인

  - git remote -v

  원격 저장소에 파일 업로드

  - 파일 생성 -> add -> commit -> push

- 기존 저장소를 Clone하여 사용하는 경우

  - git clone [URL]
  - URL : git://github.com/~~
  - 파일 생성/수정 -> add -> commit -> push



## 파일의 상태 확인하기

현재 작업 중인 브랜치와 파일 상태를 알려준다.

- 파일 상태
  - Untracked (관리대상이 아님, 빨간색 글씨로 표현돼 있다.)
  - Tracked (관리대상, 스냅샷에 포함돼 있던 파일)
    - Modified (빨간색 글씨로 표현돼 있다.)
    - Unmodified (빨간색 글씨로 표현돼 있다.)
    - Staged (초록색 글씨로 표현돼 있다.)

- git status

```bash
kkk22@LAPTOP /c/k/Study/TodayILearned (master)
$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   "Git/\352\270\260\354\241\264 \354\236\221\354\227\205\353\202\264\354\232\251 \354\236\204\354\213\234 \354\240\200\354\236\245\355\233\204 pull.md"
# 빨간색임
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        "Git/git \354\213\234\354\236\221\355\225\230\352\270\260.md"
# 빨간색임
no changes added to commit (use "git add" and/or "git commit -a")
```

```bash
kkk22@LAPTOP /c/k/Study/TodayILearned (master)
$ git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   "Git/git \354\213\234\354\236\221\355\225\230\352\270\260.md"
        modified:   "Git/\352\270\260\354\241\264 \354\236\221\354\227\205\353\202\264\354\232\251 \354\236\204\354\213\234 \354\240\200\354\236\245\355\233\204 pull.md"
# 녹색임
```



## add

Working Driectory에 있는 Untrackted files을 Stage Area에 보낸다.

- git add [file_name]



## commit

Stage Area에 있는 파일(= Staged 파일)을 내 저장소에 저장한다.

commit 명령어를 사용하면 작업 내용이 HEAD에 반영된다.

- git commit -m '[통상 commit내용(변경내역)을 명시해준다]'



## Push

commit한 사항을 원격 저장소(git repository))에 업로드한다.

- git push origin master
- git push -u origin master
  - -u 옵션은 원격 저장소로부터 업데이트 후 push한다는 의미
  - 여러명이 같은 원격 저장소를 사용하는 경우 다음 내용을 적절하게 사용
    - 브랜치 사용
    - pull -> commit -> push
    - -u push
## unstage, commit 되돌리기



### unstage

add하여 stage에 올라간 파일(녹색표시)을 되돌리고 싶으면

- 파일 한개

  git reset HEAD -- [path]/[filename]

- 모든파일

  git reset HEAD -- .

![image-20210729214219787](md-images/image-20210729214219787.png)



### commit

#### reset

돌아간 커밋 이후의 커밋은 모두 사라진다.

remote repository에 push된 커밋은 reset으로 되돌릴 수 없다.

- working directory의 파일 보존, add이후 staged 상태 (index 보존)

  git reset --soft [commit ID]

- 기본옵션, working directory의 파일 보존, add 이전 unstaged 상태 (index 취소)

  git reset --mixed [commit ID]

- working directory의 파일 삭제, add 이전 unstaged 상태 (모두 취소)

  git reset --hard [commit ID]

  

#### revert

돌아간 커밋 이후의 작업은 사라지나 revert이력이 남는다.

remote repository에 push된 커밋을 되돌리려면 revert를 사용한다.

- git revert [commit ID]

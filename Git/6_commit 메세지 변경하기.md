## Commit 메세지 변경하기

### 마지막 Commit 메세지 변경

- 바로 변경

```bash
git commit --amend -m "변경할 메세지"
```

- vi 편집기에서 커서를 위치에 놓고 i를 눌러 변경 후 esc 키 누르고 + :wq 로 저장

```bash
git commit --amend
```



### 이전 Commit 메세지 변경

- HEAD부터 3번째까지

```bash
git rebase -i HEAD~3
```

- vi 편집기에서 pick ---> reword 로 변경 후 저장 및 종료
- 위 편집기를 종료하면 한 개의 Commit 에 대한 화면이 열림
- 상단의 메세지 수정 후 저장 및 종료



### Remote에 반영하기

- 원격에 덮어쓰기
- pull 한 Commit 내용과 다른 내용의 메세지로 수정되어 있으면 협업에 혼란을 야기할 수 있음
- push 된 Commit 의 Log를 갖고 있는 팀원들이 수동으로 Log 메세지를 수정해야할 수도 있음..

```bash
git push --force
git push -f
```


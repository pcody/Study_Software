## git config
- --global 옵션으로 설치된 git의 전역 설정을 할 수 있다
- --global 옵션을 사용하지 않으면 현재 directory에만 적용되며, 전역 설정보다 우선시 된다
- 사용자 정보 (개인계정, 공인계정 등) / 기본 브랜치 (master, main 등) / 기본 에디터 (vi, vscode 등) 등을 사용자 임의로 적용할 수 있다.
  
### config 확인
```bash
git config --list
```

### config 변경
- 값이 있을 경우 삭제 먼저 진행
```bash
git config --global user.name [변경할 이름]
git config --global user.email [변경할 이메일]
```

### config 삭제
```bash
git config --unset-all --global user.name
git config --unset-all --global user.email
```
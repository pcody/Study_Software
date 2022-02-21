## git config

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
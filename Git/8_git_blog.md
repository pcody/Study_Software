## git blog

## 블로그 개설 순서
- 리포지토리 생성 (원격 저장소)
  - new repository 한다.
  - 리포지토리 이름은 [본인아이디].github.io
- 로컬 저장소 생성
  - 로컬 PC (노트북, 데스크탑 등) 에서 [본인아이디].github.io 의 리포지토리를 clone 명령어를 통해 가져온다.
    - git clone (원하는 로컬 폴더에서 명령어 실행)
  - 404에러 발생 시
    - 몇 분 기다리거나
    - 아래 명령어를 날려보거나
```bash
git commit --allow-empty -m "Trigger rebuild"
git push
```
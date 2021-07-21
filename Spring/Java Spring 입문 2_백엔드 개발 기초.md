> 자바 스프링 입문 차 인프런 김영한님의 **무료강의**를 보며 정리한 내용입니다.



## 회원관리 예제 - 백엔드 개발



### 비즈니스 요구사항 정리

- 데이터 : 회원ID, 이름

- 기능 : 회원 등록, 조회

- 일반적인 웹 어플리케이션 계층 구조

  컨트롤러 → 서비스 → 리포지토리 → DB

  　　　　↘　　↓　　↙

  　　　　　  도메인

  컨트롤러 : 웹 MVC의 컨트롤러

  서비스 : 핵심 비즈니스 로직

  리포지토리 : 데이터베이스 접근, 도메인 객체를 DB에 저장하고 관리

  도메인 : 비즈니스 도메인 객체, 예) 회원, 주문, 쿠폰 등등 주로 데이터베이스에 저장하고 관리됨

- 클래스 의존관계

  MemberService → Interface (MemberRepository)

  　　　　　　　　　　↑

  　　　　　　Memory Member Repository

  인터페이스 구현하여 클래스를 쉽게 변경할 수 있도록 설계

  RDB, NoSQL





### 회원 도메인, 리포지토리

- 비즈니스 객체(멤버) 클래스
- 멤버를 DB에 저장하고 관리하는 Interface
- Interface를 implements 하여 메소드 오버라이딩
- java method
  - HashMap<> : Map interface를 implements 한 클래스로 중복 허용하지 않으며 key 또는 value 값으로 null을 허용한다.
  - HashTable<> : Map interface를 implements 한 클래스로 중복 허용하지 않으며 key 또는 value 값으로 null을 허용하지 않는다.
  - Optional : Null값을 리턴할 때 Optional 객체로 감싸서 반환
- 

### 회원 리포지토리 테스트 케이스 작성

- 개발한 기능 테스트 방법

  - java의 main 메소드를 통해서 실행
  - 웹 애플리케이션 컨트롤러를 통해 실행
  - ↑위의 두 가지 방법은 반복 실행이 어렵고 여러 테스트를 한번에 실행하기 어렵다는 단점이 있어 이러한 문제를 해결하기 위한 방안으로 JUnit이라는 프레임워크를 사용하여 테스트 한다.

- src/test/java 하위 폴더에 패키지를 생성하여 테스트 한다.

- 테스트 파일의 모든 메소드는 순서 상관없이 동작하게끔 설계해야한다.

  -> @AfterEach annotation을 사용하여 하나의 메소드가 실행된 후 실행할 메소드를 만들어 repository의 clear 호출,

  -> repository 클래스에는 Map의 메소드 clear를 호출하는 함수를 만들어준다.





### 회원 서비스

- 회원 리포지토리를 이용하여 비즈니스 로직을 만든다.
- 비즈니스 로직은 좀 더 비즈니스적인 네이밍 규칙을 따르도록 한다.





### 회원 서비스 테스트 케이스 작성

- ctrl + t 단축키로 자동생성하면 같은 패키지명으로 src/test/java 하위에 만들어진다.

- Dependancy Injection (DI) :

  MemberService 객체를 만들 때 멤버변수인 MemberRepository 객체를

  만들어서 생성자 인자로 전달하는 방식





### 단축키

- ctrl + alt + v : 메소드 사용 형식을 자동으로 바꿔줌
- ctrl + t : 메소드로 Extract, Test 클래스 만들 때

- shift + F10 : 직전에 런 한 것을 다시 런



### 기타

- 패키지를 import하려면

  import org.assertj.core.api.Assertions;

- 패키지 내 메소드 명으로 바로 사용하려면

  import static org.assertj.core.api.Assertions.*;

  **static** 을 붙여준다.

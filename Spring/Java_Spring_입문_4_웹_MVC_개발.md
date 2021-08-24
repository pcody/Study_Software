> 자바 스프링 입문 차 인프런 김영한님의 **무료강의**를 보며 정리한 내용입니다.



## 화면관리 예제 - 웹 MVC 개발



### 홈 화면 추가

- index.html보다 컨트롤러를 먼저 찾기 때문에 ("/")을 Mapping한 컨트롤러를 먼저 찾아온다.

![image-20210721213724505](md-images/image-20210721213724505.png)

- 컨트롤러 클래스에서 (@Controller) @GetMapping("/[문자열1]/[문자열2]...") 형식으로 URL을 해당 HTML을 반환하는 메소드에 mapping해준다.

  ```java
  @GetMapping("/")
  public String home() {
      return "home";
  }
  // "home" 이라는 html문서의 이름을 String으로 반환
  ```

  

### 회원 등록 폼 개발

- URL을 주소창에 입력해서 Enter를 누르면 get 방식으로 값이 전달됨

  Controller에서 해당 URL의 GetMapping된 메소드를 찾고

  메소드의 리턴값을 template에서 찾아 html파일을 브라우저에 전달한다.

  

- 등록 폼 값 전달 순서

  ```html
  <!DOCTYPE HTML>
  <html xmlns:th="http://www.thymeleaf.org">
  <body>
  <div class="container">
      <form action="/members/new" method="post"> <!-- 여기에 표시된 URL을 찾는다 -->
          <div class="form-group">
              <label for="name">이름</label>
              <input type="text" id="name" name="name" placeholder="이름을
  입력하세요">
          </div>
          <button type="submit">등록</button>
      </form>
  </div> <!-- /container -->
  </body>
  </html>
  ```
  
  홈 화면에서 폼 링크 눌러서 등록 폼 화면으로 이동 (Get방식)
  
  등록 폼 화면에서 데이터 입력
  
  
  
  
  
  버튼을 누르면 Post방식으로 값 전달되며 
  
  controller에서 form action에 등록된 url 매핑을 찾는다 (여기서는 create)
  
  **create메소드** 실행
  
  폼으로 전달된 값은 MemberForm 객체 게터를 통해 접근 가능하며
  
  멤버 객체를 만들어 세터 메소드를 통해 멤버변수 name에 값 저장
  
  홈 화면으로 redirect
  
  ```java
  @PostMapping("/members/new")
      public String create(MemberForm form) {
          Member member = new Member();
          member.setName(form.getName());
  
          memberService.join(member);
  
          return "redirect:/";
      }
  ```



### 회원 웹 기능 조회

- memberService(비즈니스 로직)의 findMembers 메소드를 통해 모든 멤버를 List에 담는다.

- Member객체 배열(리스트) 변수 members를 model의 attributeName="members"로 담아놓고

- thymeleaf 문법으로 루프를 실행한다. (th:each)

  ```html
  <tbody>
  	<tr th:each="member : ${members}">
  	    <td th:text="${member.id}"></td>
  	    <td th:text="${member.name}"></td>
      </tr>
  </tbody>
  <!-- getter, setter의 property 접근 방식의 표현으로 "콤마(.)멤버변수명" 으로 멤버변수명을 getter, setter 대신 사용할 수 있다 -->
  ```

  ```html
  <tbody>
      <tr>
          <td>1</td>
          <td>spring1</td>
      </tr>
      <tr>
          <td>2</td>
          <td>spring2</td>
      </tr>
  </tbody>
  <!-- thymeleaf의 문법으로 th:each는 리스트 개수만큼(List<Member>) 루프를 실행한다. -->
  ```

  



### 기타

- get방식 : 조회할 때 주로 사용, URL을 그냥 치고 들어올때 get방식임
- post방식 : 값을 전달할 때 주로 사용


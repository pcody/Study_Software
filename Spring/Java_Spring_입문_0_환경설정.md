## Java Spring 환경설정



### JDK 설치 및 Java환경변수 설정

- classpath 추가

  %JAVA_HOME%\lib\tools.jar

- JAVA_HOME 추가

  C:\Program Files\jdk-11.0.11

- Path에 classpath, JAVA_HOME 추가

  %JAVA_HOME%\bin;%classpath%;

![image-20210729154423678](md-images/image-20210729154423678.png)

![image-20210729154606296](md-images/image-20210729154606296.png)





### Build가 안될 때

1. build.gradle파일을 직접 프로젝트로 열어준다. (open as a project)
2. .gradle, .idea 삭제 후 Intellij 재실행하여 1을 반복한다. (dependency 새로 import 하기)

![image-20210729141609838](md-images/image-20210729141609838.png)



![image-20210729145332688](md-images/image-20210729145332688.png)



![image-20210729145341264](md-images/image-20210729145341264.png)

3. 제일 강력한 방법으로는 Intellij 삭제하고 최신 버전으로 새로 깔았더니 잘 된다..

spring boot 2.5.3하고 gradle 7.1.1버전이 호환이 잘 안되는 듯 하다.

gradle 6.8.3으로 바꾸면 빌드가 잘 되는데, 팀원들과 동일한 버전으로 작업을 위해 인텔리제이를 새로 설치했고

참고로 java 1.8, java 14도 환경변수에서 지워버렸다.

![image-20210729154959705](md-images/image-20210729154959705.png)

![image-20210729155027508](md-images/image-20210729155027508.png)
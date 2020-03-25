# Spring 개요

* 스프링 프레임워크는 모듈로 나뉜다.

* 응용 프로그램은 필요한 모듈을 선택할 수 있으며, 핵심은 구성 모델과 의존성 주입 메커니즘을 포함한 핵심 컨테이너의 모듈이다.

* 그 외에도 메시징, 트랜잭션 데이터 및 지속성 웹을 포함한 다양한 애플리케이션 아키텍처에 대한 기본 지원을 제공한다.

* 의존성 주입(DI) 및 어논테이션(Annontations)을 지원한다.

    * IoC(Inversion of Control) : 인스턴스의 생성부터 소멸까지의 객체 생명주기를 Spring이 관리한다.

    * DI(Dependency Injection) : IoC를 실제로 구현하는 방법으로, 컴포넌트들 간의 관계를 Spring이 런타임에 찾아서 연결해준다.

* Spring Framework 5부터 WebFlux 애플리케이션은 서블릿 API를 직접 사용하지 않으며 서블릿 컨테이너가 아닌 서버에서 실행될 수 있다.

    서블릿 컨테이너는 요청이 들어올 때마다 새로운 자바 스레드를 만든다.(Tomcat)

    * 서블릿의 동작과정

        1. 사용자가 HTTP Request를 Servlet Container에 보낸다.

        2. Servlet Container는 HttpServletRequest, HttpServletResponse 객체를 생성한다.

        3. 사용자가 요청한 URL을 분석해 어느 서블릿에 대한 요청인지 찾는다.

        4. 컨테이너는 서블릿 service() 메서드를 호출하고, POST, GET여부에 따라 doGet(), doPost() 메서드가 호출된다.

        5. doGet(), doPost() 메서드는 동적인 페이지 생성 후 HttpServletResponse 객체에 응답을 보낸다.

        6. 응답이 완료되면 HttpServletRequest, HttpServletResponse 객체를 소멸시킨다.

![Servlet 동작과정](http://i.imgur.com/JaIUPwx.jpg)

    Spring Container는 Bean들의 생명주기를 관리하기위해 IoC를 사용한다.
    Spring Container의 종류에는 BeanFactory와 이를 상속한 ApplicationContext가 존재한다.

    * Spring 동작원리

        1. 웹 애플리케이션이 실행되면 Tomcat에 의해 web.xml이 loading된다.

        2. web.xml에 등록된 ContextLoaderListner(Java Class)가 생성된다.
        ContextLoaderListener 클래스는 ServletContextListener 인터페이스를 구현하고 있으며, ApplicationContext를 생성한다.

        3. ContextLoaderListener는 root-context를 loading한다.

        4. root-context에 등록된 SpringContainer가 구동된다. 이 때 개발자가 작성한 비즈니스 로직에 대한 부분과 DAO, VO 객체들이 생성된다.

        5. Client로부터 웹 애플리케이션 요청이 온다.

        6. DispatcherServlet(Servlet)이 생성된다. DispacherServlet은 클라이언트로부터 요청 온 메시지를 분석해 알맞은 PageController에게 전달하고 응답을 받아 요청에 따른 응답을 어떻게 할 지 결정한다. 실질적인 작업은 PageController에서 이루어진다.

        7. DispatcherServlet은 servlet-context를 loading한다.

        8. 두번째 Spring Container가 구동되며 응답에 맞는 PageController 들이 동작한다. 이 때 DAO, VO, Serviceplml 클래스들과 협업하여 작업을 처리하게 된다.

![Spring 동작원리](https://i.imgur.com/PlDF42i.png)

## Spring 디자인 철학

* 코드 설계를 최대한 늦출 수 있다. 예를들어 코드를 변경하지 안ㄶ고 persistence providers를 바꿀 수 있다.

* Spring은 유연성을 수용하며 다양한 관점에서 다양한 어플리케이션 요구를 지원한다.

* Spring은 신중하게 선택된 JDK 버전과 써드 파티 라이브러리를 지원하여 Spring에 의존하는 애플리케이션 및 라이브러리의 유지 보수를 용이하게 한다.

* 코드 품질에 대한 높은 표준이 필요하다. Spring은 Javadoc에 중점을 둔다.
순환 종속성이 없는 깨끗한 코드 구조를 주장 할 수 있는 프로젝트는 거의 없다.

    * 순환 종속성 문제 : 클래스 A의 생성자 주입을 통해 클래스 B의 인스턴스가 필요하고, 클래스 B의 생성자 주입을 통해 클래스 A의 인스턴스가 필요한 상황에 발생하는 문제이다.

    * 해결방법 : 상호간 단방향 의존성을 가지도록 꾸준히 관리.

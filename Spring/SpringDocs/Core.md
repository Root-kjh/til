# Spring Core

    Spring Framework에 절대적으로 필수적인 모든 기술을 다루는 문서

    이 중 가장 중요한 것은 IoC(Inversion of Control)컨테이너 이다.
    IoC 컨테이너에 대한 서술 후에는 AOP(Aspect-Oriented Programming) 기술에 대한 포괄적인 내용이 뒤따른다.

## IoC(Inversion of Control)

    IoC는 종속성 주입(DI)라고도 한다.
    
IoC는 생성자 인수, 팩토리 메소드에 대한 인수 혹은 객체 인스턴스 후에 설정된 프로퍼티나 팩토리 메서드에서 리턴받은 값으로 정의한다.

컨테이너는 Bean을 작성할 때 해당 종속성을 주입한다. 이 처리 과정은 빈 스스로 인스턴스화 하는 과정을 제어하거나 직접 클래스의 생성자를 사용해 의존성을 정의하거나 서비스 로케이터 패턴 같은 메커니즘과 근본적으로 정 반대이므로 Inversion of Control이라고 이름 붙였다.

* 생성자 주입
```java
public class Foo
{
  private IBar bar;

  public Foo(IBar bar)
  {
    this.bar = bar;
  }

  //...
}
```

* 서비스 로케이터
```java
public class Foo
{
  private IBar bar;

  public Foo()
  {
    this.bar = Container.Get<IBar>();
  }

  //...
}
```

서비스 로케이터의 경우 모든 클래스가 서비스 로케이터에 종속되기 때문에 종속성이 명시되지 않음.

org.springframework.beans 및 org.springframework.context 패키지는 스프링 IoC 컨테이너의 기반이며, BeanFactory 인터페이스는 어떤 타입의 객체도 다룰 수 있다.

ApplicationContext는 스프링의 AOP기능, 메시지 리소스 핸들링, 이벤트 발생, 웹 어플리케이션의 WebApplicationContext와 같은 어플리케이션 계층에서 지정한 Context와 더 쉽게 통합할 수 있게 한다.

요약하자면, BeanFactory는 설정 프레임워크와 기본적인 기능을 제공한다. ApplicationContext는 더 많은 엔터프라이즈 기능을 추가한다.

ApplicationContext는 BeanFactory의 SuperSet이다.

## 컨테이너 개요

org.springframework.context.ApplicationContext 인터페이스는 스프링 IoC 컨테이너를 나타내며 빈의 인스턴스화, 설정, 조합을 담당한다.

컨테이너는 메타 데이터를 읽어 어떤 객체를 인스턴스로 만들고, 설정하고, 조합해야 하는지 알아낸다.

설정 메타데이터는 어플리케이션을 구성하는 객체들을 나타내고 그러한 객체들 사이의 상호 의존성을 나타낸다.

ApplicationContext 인터페이스에는 여러 구현이 Spring과 함께 제공된다.

단독 어플리케이션에서 일반적으로 ClassPathXmlApplicationbContext나 FileSystemXmlApplicationContext의 인스턴스를 생성한다.

XML이 설정 메타 데이터를 정의하는 보편적 포맷이지만, Java Annontation이나 메타 데이터 형식의 코드로 컨테이너에 설정을 알려줄 수 있다.

대부분의 어플리케이션 시나리오에서 스프링 IoC 컨테이너의 인스턴스를 만드는 명시적인 사용자 코드는 필요하지 않다.

다음 다이어그램은 Spring의 작동 방식을 개략적으로 보여준다.

어플리케이션 클래스는 메타 데이터와 결합되어 ApplicationContext이 생성 및 초기화 된 후 인스턴스화 되면 완전히 설정이 완료되고 실행가능한 시스템이나 어플리케이션이 준비된다.

![Spring IoC Container](https://docs.spring.io/spring/docs/current/spring-framework-reference/images/container-magic.png)

### 설정 메타데이터(Configuration metadata)

설정 메타데이터를 통해 애플리케이션 개발자는 스프링 컨테이너가 어플리케이션의 객체를 어떻게 인스턴스화 하고 설정하고 조합해야 하는지 지시할 수 있다.

* 설정 메타데이터는 전통적으로 XML 포맷을 사용한다.

* XML 포맷 이외에 Annontation-based configuration 방법, Java-based configuration(@Configuration, @Bean 등 사용) 방법이 있다.

스프링 설정은 컨테이너가 반드시 관리해야 하는 최소 하나 이상의 Bean 정의로 이루어진다.

이러한 Bean 정의들은 어플리케이션을 구성하는 실제 객체들과 대응된다.

* 서비스계정 객체, 데이터 접근 객체(DAO), Struts Action 인스턴스 같은 프리젠테이션 객체, Hibernate SessionFactories 같은 인프라스트럭처 객체, JMS Queues등을 정의한다.
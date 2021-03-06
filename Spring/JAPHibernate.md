# JPA & Hibernate
---

* 인터페이스의 모음, Hibernate에서 JPA의 인터페이스를 구현한다.

* 개발자가 JPA를 사용하면, JPA 내부에서 JDBC API를 사용하여 SQL 호출, DB와 통신한다.

### JPA & Hibernate의 장점

* SQL 중심적 개발에서 객체 중심으로 개발

* 생산성

    * 간단한 CRUD

    * 특히 수정이 굉장히 간단함

* 유지보수 : 필드 변경시 SQL의 수정이 필요없음

* 약간의 성능향상

    * 캐싱 기능

    * 트랜잭션을 지원하는 쓰기 지연

    * 지연 로딩 : find 함수가 실행될 때가 아닌 값이 실제로 필요한 시점에 JPA가 SELECT 쿼리를 날림

### JPA & Hibernate의 단점

* 세밀함 : 메서드 호출로 쿼리를 날리기 때문에 세밀함이 떨어짐

    이 점을 보완하기 위해 SQL과 유사한 기술인 JPQL 지원

    SQL 자체 쿼리도 작성할 수 있음

* 높은 러닝커브 : JPA를 잘 사용하기 위해서는 알아야 할 것이 많음

## JPA & Hibernate 사용법

    DB 관련 설정을 제외한 JPA, Hibernate의 사용법만을 기술한다.

    (MySQL Database 사용)

### 의존성 설정

```xml
        <!-- 스프링 ORM -->
        <dependency>
             <groupId>org.springframework</groupId>
             <artifactId>spring-orm</artifactId>
             <version>${org.springframework-version}</version>
        </dependency>

		<!-- JPA&Hibernate -->
        <dependency>
             <groupId>org.hibernate</groupId>
             <artifactId>hibernate-entitymanager</artifactId>
             <version>5.0.11.Final</version>
        </dependency>
```

### Context 설정

```xml
	<!-- 트랜잭션 활성화 -->
	<tx:annotation-driven/>
	
	<!-- 트랜잭션 관리자 등록 -->
	<bean id="transactionManager" class="org.springframework.orm.jpa.JpaTransactionManager">
		<property name="dataSource" ref="dataSource"/>
	</bean>
	
	<!-- JPA예외 스프링 예외로 변환 -->
	<bean class="org.springframework.dao.annotation.PersistenceExceptionTranslationPostProcessor"/>
	
	<!-- JPA설정(엔티티 매니저 팩토리 등록) -->
	<bean id="entityManagerFactory" class="org.springframework.orm.jpa.LocalContainerEntityManagerFactoryBean">
		<property name="dataSource" ref="dataSource"/>
		
		<!-- Entity 탐색 범위 -->
		<property name="packagesToScan" value="com.DrK.domain"/>
		
		<!-- Hibernate 구현체 사용 -->
		<property name="jpaVendorAdapter">
			<bean class="org.springframework.orm.jpa.vendor.HibernateJpaVendorAdapter"/>
		</property>
		
		<!-- Hibernate 상세 설정 -->
        <property name="jpaProperties">
           <props>
                <prop key="hibernate.dialect">org.hibernate.dialect.MySQL5InnoDBDialect</prop> <!-- 방언 -->
                <prop key="hibernate.show_sql">true</prop>                          <!-- SQL 보기 -->
                <prop key="hibernate.format_sql">true</prop>                        <!-- SQL 정렬해서 보기 -->
                <prop key="hibernate.use_sql_comments">true</prop>                  <!-- SQL 주석 보기 -->
                <prop key="hibernate.id.new_generator_mappings">true</prop>         <!-- JPA 표준에 맞게 새로운 키 생성 전략을 사용-->
                <prop key="hibernate.hbm2ddl.auto">none</prop>
            </props>
         </property>

        <!-- service, repositories package 경로 등록 -->
        <context:component-scan base-package="com.DrK.service, com.DrK.repositories">
                <context:include-filter type="annotation"
                        expression="org.springframework.stereotype.Repository" />
                <context:include-filter type="annotation"
                        expression="org.springframework.stereotype.Service" />
                <context:include-filter type="annotation"
                        expression="org.springframework.stereotype.Component" />
        </context:component-scan>
	</bean>
```

* Entity : 테이블로 매핑 시킬 객체

* hibernate.hbm2ddl.auto 옵션 : 애플리케이션이 실행될 때 기존의 데이블을 삭제하고 새로운 테이블을 생성할지에 대한 옵션

    1. none : 기본값, 아무 일도 일어나지 않음

    2. create-only

    3. drop

    4. create

    5. create-drop : SessionFactory가 시작될 때 스키마를 drop& creat 하며, SessionFactory가 종룔될 때도 스키마를 drop함

    6. validate : 스키마 검증

    7. update : 스키마 갱신

### Entity Mapping

#### UserVO 생성

```java
package com.DrK.domain;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

import lombok.Data;

@Data
@Entity
@Table(name = "User")
public class UserVO {
	
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private long idx;
	
	@Column(name = "id", nullable = false, length = 50)
	private String id;
	
	@Column(name="password", nullable = false, length = 65)
	private String password;
}
```

* @Entity : Entity 선언

    * Options

        1. name : JPA가 사용할 엔티티 이름 지정

* @Table : 엔티티 클래스에 매핑할 테이블 정보 명시

    * Options

        1. name : 테이블 이름

        2. schema : schema 기능이 있는 DB에서 schema Mapping

* @Id : 테이블의 기본 키(Primary Key)에 매핑

* @GenerateValue : 기본 키 생성 전략

    * Options

        1. strategy : 대리 키 사용 방식

            * AUTO : DB 종류에 따라 알맞은 것을 선택

            * IDENTITY : 기본 키 생성을 DB에 위임

                (MySQL, PostgreSQL, SQL Server, DB2)

            * SEQUENCE : DB Sequence 사용

                (Oracle, PostgreSQL, DB2, H2)

            * TABLE : 키 전용 테이블을 만들어 Sequence처럼 사용

* @Column

    * Options

        1. name : 컬럼 이름

        2. nullable : nulll 허용 여부

        3. length : 문자 길이 제약 조건

* @Temporal : 날짜 타입 매핑시 사용

    * Options

        1. TemporalType.DATE

        2. TemporalType.TIME
        
        3. TemporalType.TIMESTAMP

* @Transient : 매핑이 이루어지지 않는 객체

* @Enumerated : Java의 Enum타입 매핑시 사용

    * Options

        1. EnumType.ORDINAL

        2. EnumType.STRING

* 매핑 정보가 없을 때

    * 매핑 어노테이션을 생략하면 필드명을 그대로 칼럼명으로 매핑

### Repository 구현

```java
package com.DrK.repositories;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.TypedQuery;

import org.springframework.stereotype.Repository;

import com.DrK.entities.User;

@Repository
public class UserRepository{

	@PersistenceContext // EntityManagerFactory가 DI 할 수 있도록 설정
	private EntityManager em;
	
	public List<User> findAll(){
		String jpql="select u from User u order by u.idx desc";
		TypedQuery<User> query=em.createQuery(jpql,User.class);
		
		return query.getResultList();
	}
}
```

### JPQL

    SQL과 비슷한 문법을 가진 객체 지향 쿼리

### JPQL의 특징

* 대소문자 구분 : 엔티티와 속성은 대소문자를 구분한다.

* 엔티티 이름 : FROM 뒤에 설정한 엔티티의 이름을 넣어야함

* 별칭 : 엔티티의 별칭 명시 강제

### JPQL 쿼리 종류

* TypedQuery

    ```java
    	public List<User> findAll(){
		String jpql="select u from User u order by u.idx desc";
		TypedQuery<User> query=em.createQuery(jpql,User.class);
		
		return query.getResultList();
	}
    ```

    모든 리스트를 조회하는 쿼리

* Query

    ```java
    public static void Query(EntityManager em) {
	String jpql = "SELECT b.no, b.title FROM Book b";
	Query query = em.createQuery(jpql);
	
	List<Object> list = query.getResultList();
	for( Object object : list ) {
	      Object[] results = (Object[]) object;
	      
	      for( Object result : results ) {
	          System.out.print ( result );
	     }
	     System.out.println();
	  }
    }
    ```

    검색 결과의 타입을 명시하지 않음

    여러 개의 칼럼 선택적 명시 가능

* setParameter

    ```java
    public static void namedParameter(EntityManager em, String param1) {
        String jpql = "SELECT b FROM Book b WHERE title = :foo";
        TypedQuery<Book> query = em.createQuery(jpql, Book.class);
        query.setParameter("foo", param1);
        
        List<Book> bookList = query.getResultList();
        for( Book book : bookList) {
            System.out.println(book.getTitle());
        }
    }
    ```

    이름을 기준으로 파라미터 바인딩

    ```java
    public static void NamedParameter2(EntityManager em, String param1) {
        String jpql = "SELECT b FROM Book b WHERE title = ?1";
        TypedQuery<Book> query = em.createQuery(jpql, Book.class);
        query.setParameter(1, param1);
        
        List<Book> bookList = query.getResultList();
        for( Book book : bookList) {
            System.out.println(book.getTitle());
        }
    }
    ```

    위치를 기준으로 파라미터 바인딩

    setParameter를 사용하지 않고 쿼리에 직접 바인딩 할 경우, SQL Injection의 위험이 있음

## 영속성 컨텍스트(Persistence Context)

    엔티티 매니저로 엔티티를 저장, 조회 하면 엔티티 매니저는 그 엔티티를 영속성 컨텍스트에 보관하고 관리함

* Persistence Context는 @Id 필드를 이용해 엔티티를 식별하기 때문에 @Id가 꼭 있어야함

### 엔티티 생명주기

1. 비영속(new)

    DB와 관련 없는 순수 객체상태

2. 영속(managed)

    Persistence Context에 엔티티가 저장된 상태

    persist() 메서드 호출, 엔티티 조회시 영속상태라 함

3. 준영속(detached)

    매니저가 관리하지 않는 상태

    detach, clear, close 메서드 호출시 준영속 상태라 함

4. 삭제

    persistence context에서 엔티티를 제거하며, DB에서도 해당 객체 삭제

    remove() 메서드를 호출하여 삭제할 수 있음

### 영속성 컨텍스트의 특징

* 1차 캐시

    Managed 상태의 엔티티를 찾는 경우, SELECT 쿼리를 수행하지 않고 바로 반환함

* 동일성 보장

    1차 캐시 기능에 의해 같은 엔티티를 반환하므로 동일성 비교 결과(a==b) true가 반환됨

* 쓰기 지연

    INSERT 쿼리의 경우 쿼리 저장소에 저장되어 있다가 엔티티 매니저가 commit,flush 매서드를 호출할 때 한번에 쿼리가 실행됨

* 변경 감지

    엔티티가 1차 캐시에 최초로 저장될 때, 스냅샷을 찍어 저장하는데, 이후 flush 시점에서 스냅샷과 현재 상태를 비교해 엔티티가 변경되었다면 UPDATE 쿼리를 실행함.

* 삭제

    remove 메서드도 INSERT와 같이 쓰기 지연이 적용됨

* 준영속(Detached)

    detach 메서드를 호출해 엔티티를 준영속 상태로 만듦

    clear 메서드 호출 시 모든 엔티티들을 준영속 상태로 만들고, close 메서드 호출 시 persistence context를 종료함

* merge

    준영속 상태를 다시 영속상태로 변환하지 않고, managed 상태인 새로운 엔티티를 반환함

### 연관관계 매핑

#### 용어정리

* 단방향 관계 : 두 엔티티 중 한 쪽의 엔티티만 참조하고 있는 것

* 양방향 관계 : 양 쪽이 서로 참조하고 있는 것

#### 다중성

* Many To One : 다대일(N:1)

* One To Many : 일대다(1:N)

* One To One : 일대일(1:1)

* Many To Many : 다대다(M:N)

#### 연관 관계의 주인

    연관 관계를 갖는 두 테이블에 대해 외래키를 갖는 테이블이 연관 관계의 주인

    연관관계의 주인만이 외래키의 관리 가능

#### 예시

1. ManyToMany - 단방향

```java
@Entity
@Table(name="category")
public class Category {
	@Id
	@Column(name="no")
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	private Integer no;
	
	@Column( name="name", nullable=false, length=100 )
	private String name;
	
	// getter , setter 생략
	
}


@Entity
@Table( name="book")
public class Book {
	@Id
	@Column(name="no")
	@GeneratedValue( strategy = GenerationType.IDENTITY )
	private Integer no;
	
	@Column(name="title", nullable=false, length=200)
	private String title;
	
	@ManyToOne
	@JoinColumn(name ="category_no")
	private Category category;
	
	// getter , setter 생략
	
}
```

@JoinColumn으로 외래키 매핑 : 필드명+"_"+참조하는 테이블의 컬럼명

2. OneToMany - 양방향

```java
@Entity
@Table(name="category")
public class Category {
	@Id
	@Column(name="no")
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	private Integer no;
	
	@Column( name="name", nullable=false, length=100 )
	private String name;

	@OneToMany(mappedBy="category")
	private List<Book> books = new ArrayList<Book>();
	
	// getter , setter 생략
	
}
```

@OneToMany 어노테이션에 maapedBy 속성을 추가 해 category 엔티티에 의해 books 필드가 매핑됨을 명시

Persistence Context에서 카테고리 엔티티가 책 엔티티의 정보를 갖고 있지 않을경우 해당 엔티티는 출력되지 않음

따라서 category 엔티티의 books 필드에 해당 book의 정보를 추가해야함

```java
book.getCategory().getBooks().add(book);
```

3. OneToOne

    * 단방향

        ```java
        @Entity
        @Table(name="user")
        public class User {
            @Id
            @GeneratedValue(strategy=GenerationType.AUTO)
            @Column(name="no")
            private Integer no;
            
            @Column(name="id")
            private String id;

            @OneToOne
            @JoinColumn(name="blog_no")
            private Blog blog;
        }


        @Entity
        @Table(name="blog")
        public class Blog {
            @Id
            @GeneratedValue(strategy=GenerationType.AUTO)
            @Column(name="no")
            private Integer no;
            
            @Column(name="name")
            private String name;
        }

        ```

    * 양방향

        ```java
        @Entity
        @Table(name="blog")
        public class Blog {
            @Id
            @GeneratedValue(strategy=GenerationType.IDENTITY)
            @Column(name="no")
            private Integer no;
            
            @Column(name="name")
            private String name;
            
            @OneToOne(mappedBy="blog")
            private User user;	
        }
        ```

4. ManyToMany

    * 단방향

        ```java
        @Entity
        @Table(name="user")
        public class User {
            @Id
            @GeneratedValue(strategy=GenerationType.IDENTITY)
            @Column(name="no")
            private Integer no;
            
            @Column(name="id")
            private String id;

            @ManyToMany
            @JoinTable(name="user_product",
                        joinColumns = @JoinColumn(name = "user_no"),
                        inverseJoinColumns = @JoinColumn(name = "product_no"))
            private List<Product> product = new ArrayList<Product>();
        }


        @Entity
        @Table(name="product")
        public class Product {
            @Id
            @GeneratedValue(strategy=GenerationType.IDENTITY)
            @Column(name="id")
            private Integer id;
            
            @Column(name="name")
            private String name;
        }
        ```

        * @JoinTable : M:N관계에서 생성할 테이블 명 정의

            * Options

                * name : 테이블 이름

                * joinColumns : join을 수행할 컬럼의 이름

                * inverseJoinColumns : join을 수행할 다른 컬럼 이름

    * 양방향

        ```java
        @Entity
        @Table(name="product")
        public class Product {
            @Id
            @GeneratedValue(strategy=GenerationType.IDENTITY)
            @Column(name="id")
            private Integer id;
            
            @Column(name="name")
            private String name;

            @ManyToMany(mappedBy="products")
            private List<User> users = new ArrayList<User>();

        }
        ```

## JPA 상속

JPA는 상속을 해결하기 위해 3가지의 방식을 지원한다.

1. Joined

    * 장점

        * 테이블의 정규화

        * 외래 키 참조 무결성 제약조건 사용가능

        * 저장공간의 효율적 사용

    * 단점

        * 조인의 사용으로 인한 성능 저하

        * 조회 쿼리의 복잡화

        * insert 쿼리가 두번씩 실행되어야 함

2. Single_Table : Joined 방식으로 엮여있는 테이블들을 하나의 테이블로 합침

    * 장점

        * 조인을 쓰지 않아 조회 성능이 좋음

        * 조회 쿼리의 단순화

    * 단점

        * 자식 엔티티가 매핑한 컬럼은 모두 null을 허용해야 함

        * 테이블이 커짐, 그로 인해 성능이 오히려 느려질 수 있음

3. Table_Per_Class : 구혀 클래스마다마다 테이블을 만듬

    * 장점 

        * 서브 타입을 구분해서 처리할 때 효과적

        * not null 제약조건 사용가능

    * 단점

        * 여러 자식테이블을 함께 조회할 때 성능이 느림(UNION을 사용해야함)

        * 자식테이블을 통합해 쿼리하기 어려움

### 지연로딩과 프록시

    지연로딩의 사용시 프록시 객체가 필요함

* 프록시 : 실제 엔티티 대신 사용되는 객체, 실제 엔티티와 상속 및 위임 관계에 있음

```java
public static void proxy1(EntityManager em) {
	// Entity proxy 객체 반환
	// Book 엔티티를 상속받은 Book Proxy를 리턴
	Book book = em.getReference(Book.class, 1);
	
	// System.out.println(book.getTitle());
}
```

book proxy를 얻을때 select 쿼리가 실행되지 않음

실제로 print 구문의 주석을 풀고 실행해야 select 쿼리가 실행됨

#### 프록시 초기화

    프록시 객체가 참조하는 실제 엔티티가 persistence context에 생성되어 있지 않을 때, 실제 엔티티 생성을 요청하고 그것을 프록시에 할당하는 과정 

    프록시의 초기화 시 지연로딩 방식에서 DB에 접근해 엔티티를 가져온다.

![프록시 초기화의 과정](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F998777345AE567D42BB022)

출처 : [victolee](https://victorydntmd.tistory.com/)

### JPA의 역사

1. JDBC(MyBatis) 의 반복적 CRUD 작업 해결 및 객체 지향적 개발 방법 사용의 목적으로 JPA가 개발됨

2. JPA의 기본적인 메서드만으로 복잡한 검색이 불가능해 SQL과 유사한 JPQL이 도입됨

3. JPQL 사용 시 문법적 오류 발생 가능성의 문제, 좀 더 높은 생산성을 이유로 QueryDSL 사용

    * QueryDSL : 메서드 호출만으로 쿼리 생성

4. QueryDSL로도 반복적인 CRUD 작업 진행으로 인해 Spring-Data-JPA의 개발

* Spring-Data-JPA

    Repository 계층의 반복적 작업을 피하기 위해 기본적인 CRUD 메서드가 포함된 JpaRepository 인터페이스 제공

    필요한 쿼리를 수행하기 위한 메서드 직접 정의 가능

### Spring-Data-JPA의 사용

#### 종속성 추가

```xml
		<dependency>
		    <groupId>org.springframework.data</groupId>
		    <artifactId>spring-data-jpa</artifactId>
		    <version>2.2.3.RELEASE</version>
		</dependency>
```

#### Context 설정 변경

    트랜잭션 persistence context 관련 설정과 jpa-repositories base-package 등록

```xml
	<!-- 트랜잭션 활성화 -->
	<tx:annotation-driven/>
	
	<!-- 트랜잭션 관리자 등록 -->
	<bean id="transactionManager" class="org.springframework.orm.jpa.JpaTransactionManager">
		<property name="dataSource" ref="dataSource"/>
	</bean>
	
	<!-- JPA예외 스프링 예외로 변환 -->
	<bean class="org.springframework.dao.annotation.PersistenceExceptionTranslationPostProcessor"/>
	
	<!-- JPA설정(엔티티 매니저 팩토리 등록) -->
	<bean id="entityManagerFactory" class="org.springframework.orm.jpa.LocalContainerEntityManagerFactoryBean">
		<property name="dataSource" ref="dataSource"/>
		
		<!-- Entity 탐색 범위 -->
		<property name="packagesToScan" value="com.DrK.entities"/>
		
		<!-- Hibernate 구현체 사용 -->
		<property name="jpaVendorAdapter">
			<bean class="org.springframework.orm.jpa.vendor.HibernateJpaVendorAdapter"/>
		</property>
		
		<!-- Hibernate 상세 설정 -->
        <property name="jpaProperties">
           <props>
                <prop key="hibernate.dialect">org.hibernate.dialect.MySQL5InnoDBDialect</prop> <!-- 방언 -->
                <prop key="hibernate.show_sql">true</prop>                          <!-- SQL 보기 -->
                <prop key="hibernate.format_sql">true</prop>                        <!-- SQL 정렬해서 보기 -->
                <prop key="hibernate.use_sql_comments">true</prop>                  <!-- SQL 주석 보기 -->
                <prop key="hibernate.id.new_generator_mappings">true</prop>         <!-- JPA 표준에 맞게 새로운 키 생성 전략을 사용-->
                <prop key="hibernate.hbm2ddl.auto">none</prop>
            </props>
         </property>
	</bean>

	<jpa:repositories base-package="com.DrK.repositories"/>
```

#### Repository 구현

```java
package com.DrK.repositories;

import org.springframework.data.jpa.repository.JpaRepository;
import com.DrK.entities.User;

public interface UserRepository extends JpaRepository<User, Integer>{

}
```

### Spring-Data-JPA에서 제공하는 메서드

* save() : insert 및 update

* delete()

* findOne() : 하나의 엔티티 조회

* getOne() : 엔티티가 아닌 프록시로 조회

* findAll() : 모든 엔티티 조회

# MySQL
---

## MySQL(RDBMS) 사용 이유

* 데이터 무결성 보장 : 회원 데이터관리에 필요

* 데이터가 자주 수정됨 : NoSQL은 데이터 수정 시 모든 컬렉션이 업데이트 되어야 하기 때문에 성능면에서 좋지 못함

* Join문 사용

## Spring MySQL 연동

### 의존성 추가

```xml
		<!-- https://mvnrepository.com/artifact/mysql/mysql-connector-java -->
		<dependency>
		    <groupId>mysql</groupId>
		    <artifactId>mysql-connector-java</artifactId>
		    <version>8.0.19</version>
		</dependency>
```

### MySQL DataSource Bean 추가

```xml
	<bean id="dataSource"
		class="org.springframework.jdbc.datasource.DriverManagerDataSource">
		<property name="driverClassName" value="com.mysql.cj.jdbc.Driver"/>
		<property name="url"
			value="jdbc:mysql://18.188.97.66/Recruit_List"/>
		<property name="username" value="ID"/>
		<property name="password" value="Passwd"/>
	</bean>
```

### 테스트코드 작성

```java
	@Setter(onMethod_ = {@Autowired})
	private DataSource MySQLConnector;

    @Test
	public void MySQLConnectTest() {
		log.info(MySQLConnector);
	}
```
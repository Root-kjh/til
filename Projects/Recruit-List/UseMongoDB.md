# MongoDB
---

## MongoDB란

     Document-Oriented(문서 지향적) NoSQL 데이터베이스이다.

* NoSQL(Not Only SQL) : RDBMS의 한계를 극복하기 위한 새로운 형태의 데이터베이스

* Document : JSON Objects 형태의 Key-Value의 쌍으로 이루어진 데이터 구조로 구성됨

```json
{
  _id: ObjectId("5099803df3f4948bd2f98391"),
  name: { first: "Alan", last: "Turing" },
  birth: new Date('Jun 23, 1912'),
  death: new Date('Jun 07, 1954'),
  contribs: [ "Turing machine", "Turing test", "Turingery" ],
  views : NumberLong(1250000)
}
```

* 각 Document는 _id라는 고유한 값을 가진다.


* MongoDB 구조

![MongoDB 구조](https://poiemaweb.com/img/mongodb-structure.png)
[출처 : poiemaweb](https://poiemaweb.com/)

* Collection : RDBMS의 Table과 유사한 개념, Documnet들의 집합으로 구성된다.

* Database : Collection들의 물리적 컨테이너

## MongoDB의 특징

* Schema-less : 고정적인 스키마가 존재하지 않아 같은 Collection 내의 Document 끼리 다른 Schema를 가질 수 있다.

* JOIN 기능이 없어 Table JOIN은 효과적이지 않지만 CRUD Query는 고속으로 동작한다. & 하나의 Document(포스트)에 Sub Document로 댓글을 포함시킨다.

## MongoDB 설치

* Repository 추가

```conf
[mongodb-org-4.0]
name=MongoDB Repository
baseurl=https://repo.mongodb.org/yum/redhat/7/mongodb-org/4.0/x86_64/
gpgcheck=1
enabled=1
gpgkey=https://www.mongodb.org/static/pgp/server-4.0.asc
```

* MongoDB 설치

```
yum -y install mongodb-org
```

* /etc/mongod.conf 설정

```conf
net:
    port: 27017
    bindIp: 0.0.0.0 # 모든 IP의 연결 허용
```

* MongoDB start

```
service mongod start
```

## Spring MongoDB 연동

### 의존성 추가

    spring과 버전 충돌 문제가 발생해 springframework의 버전을 5.2.3.RELEASE로 변경

```xml
		<!-- MongoDB -->
        <dependency>
            <groupId>org.mongodb</groupId>
            <artifactId>mongo-java-driver</artifactId>
            <version>3.11.0</version>
        </dependency>
        <dependency>
            <groupId>org.springframework.data</groupId>
            <artifactId>spring-data-mongodb</artifactId>
            <version>2.1.8.RELEASE</version>
        </dependency>
```

### root-context 수정

```xml
	<mongo:mongo-client
		host="18.188.97.66"
		port="27017"
		credentials="Recruit_List:Recruit_List@Recruit_List"
	/>
	
	<mongo:db-factory
		mongo-ref="mongoClient"
		dbname="Recruit_List"
	/>

	<mongo:repositories base-package="com.DrK.repositories"/>
```

### 테스트코드 작성

```java
package com.DrK.persistence;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.mongodb.core.MongoTemplate;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class DB_Connect {

	@Setter(onMethod_ = {@Autowired})
	private MongoTemplate mongoTemplate;
	
	@Test
	public void test_connection() {
		log.info(mongoTemplate);
	}
}
```

## Repository 구현

### Entity 생성

```java
package com.DrK.entities;

import javax.persistence.Id;

import org.springframework.data.mongodb.core.mapping.Document;

import lombok.Data;

@Data
public class Company {
	
	@Id
	private String id;
	
	private String CompanyName;
}
```

### Repository 생성

```java
package com.DrK.repositories;

import org.springframework.data.mongodb.repository.MongoRepository;

import com.DrK.entities.Company;

public interface CompanyRepository extends MongoRepository<Company, String>{
}
```

### 테스트코드 작성

```java
package com.DrK.repositories;

import org.bson.types.ObjectId;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import com.DrK.entities.Company;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class CompanyRepositoryTest {

	@Setter(onMethod_ = {@Autowired})
	private CompanyRepository companyRepository;
	
	@Test
	public void getAllList() {
		for (Company company: companyRepository.findAll()) {
			log.info(company.getCompanyName());
		}
	}
}
```

## Service 구현

### 인터페이스 작성

```java
package com.DrK.service;

import java.util.List;

import com.DrK.entities.Company;

import lombok.Setter;

public interface CompanyService {

	public List<Company> getList();
}
```

### Service 구현

```java
package com.DrK.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.mongodb.core.MongoTemplate;
import org.springframework.stereotype.Service;

import com.DrK.entities.Company;
import com.DrK.repositories.CompanyRepository;

import lombok.AllArgsConstructor;
import lombok.Setter;

@Service
@AllArgsConstructor
public class CompanyServicelmpl implements CompanyService{

	@Setter(onMethod_ = {@Autowired})
	private MongoTemplate mongoTemplate;
	
	@Override
	public List<Company> getList() {
		return mongoTemplate.findAll(Company.class,"company");
	}

}
```

### 테스트코드 작성

```java
package com.DrK.service;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import com.DrK.entities.Company;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class CompanyServiceTest {

	@Setter(onMethod_ = {@Autowired})
	private  CompanyService companyService;
	
	@Test
	public void getListTest() {
		for (Company companyVO : companyService.getList()) {
			log.info(companyVO);
		}
	}
}
```
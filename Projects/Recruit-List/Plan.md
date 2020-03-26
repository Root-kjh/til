# 프로젝트 계획
---

## 서비스 정리

* Company

    * 병무청에서 병역채용이 가능한 회사 리스트를 크롤링 해 DB Update

    * 해당 회사에 대한 정보&채용정보 각종 채용정보 사이트&회사 홈페이지 에서 크롤링

* User

    * 사용자가 관심있어 하는 회사 저장

## DB 설계

* Company

![Company DB Struct](/Projects/Recruit-List/img/Service_Struct_Company.png)

각 채용정보 사이트에 내용이 없을경우, Null값으로 들어가는 컬럼이 많고, 대부분 상시채용인 병역채용 특성상 데이터의 수정이 많지 않을 것으로 예상

MongoDB 사용

* User

![User DB Struct](/Projects/Recruit-List/img/Service_Struct_User.png)

정보 업데이트의 빈도 수를 예상할 수 없고, 데이터의 구조가 정해져 있으며 정규화 필요.

MySQL 사용

## 크롤링

* Javascript를 사용해 데이터가 동적으로 변화 될 수 있음 -> Selenium 사용

* Selenium을 사용해봤으며, 가장 익숙한 언어 -> Python 사용

## 인증 관련

* jwt 사용
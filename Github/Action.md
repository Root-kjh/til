# Action
---

## Action

* Github 내에서 코드 프로젝트를 빌드, 테스트, 패키지, 릴리스 or 배포 하기 위해 설정할 수 있는 사용자 지정 자동화 프로젝트

* Action에는 크게 4가지의 주요 개념이 있다.

### Workflow

* 프로젝트를 빌드, 테스트, 릴리스 or 배포하기 위한 전체적인 프로세스

* Workflow는 여러 개의 job으로 구성되며, event에 의해 실행된다.

* Github에게 나만의 동작을 정의한 workflow file을 만들어 전달하면 Github Action이 그것으 보고 그대로 실행시켜준다.

### Job

* 하나의 인스턴스에서 여러 Step을 그룹시켜 실행하는 역할

* jobs: 하위에 여러개의 job을 선언할 수 있고, 기본적으로 job들은 병렬로 실행된다.

### Step

* 순차적으로 명령어를 수행한다.

* 크게 User와 Run으로 작업 단위가 나뉜다.

* User은 이미 다른 사람들이 정의한 명령어를 가져와 실행한다.

* Run은 npm install이나 mkdir example과 같이 가상환경 내에서 실행할 수 있는 스크립트를 말한다.

### Event

* 워크플로우를 실행시키는 조건을 설정한다.

* 해당 레포지토리에 Code가 push 됐을 때, master branch에 변경사항이 있었을 때 등으로 조건을 줄 수 있다.
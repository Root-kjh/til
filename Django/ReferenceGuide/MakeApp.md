# 앱 작성하기
>파이썬으로 이루어진 무료 오픈소스 웹 프레임워크

## Django의 동작 구조

* Request 요청이 Django로 전달.

* urlresolver는 url을 가져와 일치하는 패턴의 함수(view)에 전달.

* 권한 확인 후 Response return

## Django 설치

```
pip install Django
```

### Apache와 mod_wsgi 설치



## Django 환경구성

```
django-admin startproject project-name

python manage.py startapp app-name
```

## Django 시작 명령어

```
python manage.py runserver
```

## View 작성

* views.py

```python
from django.shortcuts import render
from django.http import HttpResponse

def index(request):
    return HttpResponse("Heelo world. You're at the polls index.")
```

* urls.py

```python
from django.urls import path

from . import views

urlpatterns = [
    path('',views.index,name='index'),
]
```

* mysite의 urls.py 파일 수정

```python
from django.contrib import admin
from django.urls import include,path

urlpatterns = [
    path('polls/',include('polls.urls')),
    path('admin/', admin.site.urls),
]
```

* path() 메서드의 인수

    * route(필수) : url패턴을 가진 문자열

    * view(필수) : Django에서 일치하는 패턴을 찾으면, HttpRequest 객체를 첫번째 인수로 하고, 경로로부터 '캡처된' 값을 키워드 인수로 하여 특정한 view 함수 호출

    * kwargs(선택) : 임의의 키워드 인수들은 목표한 view에 사전형으로 전달됨

    * name(선택) : URL에 이름을 지으면, 템플릿을 포함한 Django 어디에서나 명확하게 참조할 수 있음

## Django Settings

    Settings 파일 수정

```python
LANGUAGE_CODE = 'ko-KR' # 북한의 LANGUAGE_CODE는 "ko-KP" 이다.

TIME_ZONE = 'Asia/Seoul'
```

* INSTALLED_APPS

    Django 인스턴스에서 활성화된 모든 Djnago 어플리케이션들을 지정

    * django.contrib.admin

        자동 관리 도구, /admin/ 페이지에서 관리 페이지를 이용할 수 있다.

    * django.contrib.auth

        사용자 계정, 그룹, 권한과 쿠키 기반의 사용자 세션을 다룬다.

    * django.contrib.contenttypes

        하나의 테이블에서 범용적으로 다른 테이블에 Join할 때 사용

    * django.contrib.sessions

        익명 세션을 완벽하게 지원

    * django.contrib.messages

        일회성 메시지에(플레시 메시지) 대한 지원

    * django.contrib.staticfiles

        정적 파일을 프로덕션에서 쉽게 제공 할 수 있는 단일 위치로 수집

### Django DB Setting

#### 데이터베이스 패키지 설치

* PostgreSQL
```
pip install psycopg2
```

* Oracle
```
pip install cx_Oracle
```

#### Setting DATABASES

```python
DATABASES = {
    'default':{
        'ENGINE': 'DatabaseEngine',
        'NAME': 'database_name',
        'USER':'USER',
        'PASSWORD':'PASSWORD',
        'HOST':'127.0.0.1',
        'PORT':'DatabasePort',
    }
}
```

* ATOMIC_REQUEST

    Default : False

    DB 트랜잭션 관리

* AUTOCOMMIT

    Default : True

* ENGINE

    SQLITE : django.db.backends.sqlite3

    PostgreSQL : django.db.backends.portgresql

    Mysql : django.db.backends.mysql

    Oracle : django.db.backends.oracle

* HOST

* NAME

    DB Name

* ONN_MAX_AGE

    Default : 0

    DB 연결 수명(초)

* OPTIONS

    Default : {}

    추가 매개변수

* PASSWORD

* PORT

* TIME_ZONE

    Default : Settings의 TIME_ZONE과 동일한 값 사용

* DISABLE_SERVER_SIDE_SURSORS

    Default : False

    PortgreSQL 관련 설정

* USER

* TEST

    테스트를 위한 데이터베이스 작성. 테스트가 실행되면 테스트 DB가 삭제됨

    Default : {}

    * CHARSET

    * COLLATION

    * DEPENDENCIES

    * MIRROR

        여러 db의 복제본 구성을 테스트 할 수 있도록 함

    * NAME

    * SERIALIZE

    * TEMPLATE

    ---
    Oracle 특정 설정

    * CREATE_DB

    * USER

    * PASSWORD

    * ORACLE_MANAGED_FILES

    * TBLSPACE

    * TBLSPACE_TMP

    * DATAFILE

    * DATAFILE_TMP

    * DATAFILE_MAXSIZE

    * DATAFILE_TMP_MAXSIZE

    * DATAFILE_SIZE

    * DATAFILE_TMP_SIZE

    * DATAFILE_EXTSIZE

    * DATAFILE_TMP_EXTSIZE

## 모델 만들기

    모델이란 부가적인 메타데이터를 가진 데이터베이스의 구조를 말합니다.

    Django는 DRY(Don't Repeat Yourselt) 원칙을 따릅니다. 이 원칙에 따라 데이터 모델을 한곳에서 정의하고, 이것으로 부터 자동으로 뭔가를 유도하는 것이 목표입니다.

```python
from django.db import models

class Question(models.Model):
    question_text=models.CharField(max_length=200)
    pub_date=models.DateTimeField('date published')

class Choice(models.Model):
    question=models.ForeignKey(Question,on_delete=models.CASCADE)
    choice_text=models.CharField(max_length=200)
    votes=models.IntegerField(default=0)
```

각 모델은 서브 클래스로 표시됩니다. 각 모델에는 여러 클래스 변수가 있으며 각 변수는 모델의 데이터베이스 필드를 나타냅니다.

### 모델의 활성화

    Django는 모델 코드를 이용해 데이터베이스 스키마를 생성하고 Question과 Choice 객체에 접근하기 위한 Python DB 접근 API를 생성한다.

먼저, 현재 프로젝트에 polls 앱이 설치되어 있다는 것을 알리기 위해

INSTALLED_APPS 설정을 수정한다.

```python
INSTALLED_APPS = [
    'polls.apps.PollsConfig',
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
]
```

```
python manage.py makemigrations polls
```

makemigrations를 실행시킴으로서, 모델을변경(생성)한 사실과 변경사항을 migration으로 저장시키고 싶다는 것을 Django에게 알린다.

```
python manage.py sqlmigrate polls 0001
```

sqlmigrate 명령은 migration 이름을 인수로 받아 실행하는 SQL 문장을 보여준다.

```SQL
BEGIN;
--
-- Create model Question
--
CREATE TABLE "polls_question" ("id" integer NOT NULL PRIMARY KEY AUTOINCREMENT, "question_text" varchar(200) NOT NULL, "pub_date" datetime NOT NULL);
--
-- Create model Choice
--
CREATE TABLE "polls_choice" ("id" integer NOT NULL PRIMARY KEY AUTOINCREMENT, "choice_text" varchar(200) NOT NULL, "votes" integer NOT NULL, "question_id" integer NOT NULL REFERENCES "polls_question" ("id") DEFERRABLE INITIALLY DEFERRED);
CREATE INDEX "polls_choice_question_id_c5b4b260" ON "polls_choice" ("question_id");
COMMIT;
```

* 테이블 이름은 앱의 이름과 모델의 이름이 조합되어 자동으로 생성된다.

* Django는 외래 키 필드명에 "_id" 이름을 자동으로 추가한다.

```
python manage.py migrate
```

migrate를 실행시켜 DB에 모델과 관련된 테이블을 생성한다.

## API 사용

```
python manage.py shell
```

manage.py shell 명령은 Python 쉘에서 Djnago 명령을 사용할 수 있게 한다.

```python
PS C:\Users\wldnr\Documents\VisualCode\DjangoDocs\mysite> python .\manage.py shell
Python 3.8.1 (tags/v3.8.1:1b293b6, Dec 18 2019, 22:39:24) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license" for more information.
(InteractiveConsole)
>>> from polls.models import Choice, Question
>>> Question.objects.all()
<QuerySet []>
>>> from django.utils import timezone
>>> q=Question(question_text="What's new?", pub_date=timezone.now())
>>> q.save()
>>> q.id
1   
>>> q.question_text
"What's new?"
>>> q.pub_date
datetime.datetime(2020, 3, 7, 18, 57, 59, 548485, tzinfo=<UTC>)
>>> q.question_text="What's up?"
>>> q.save()
>>> Question.objects.all()
<QuerySet [<Question: Question object (1)>]>
```

여기서  <Question: Question object (1)>는 객체를 표현하는데에 도움이 되지 않기 때문에 Question 모델을 수정해 `__str__()` 메소드를 Question과 Choice에 추가한다.

```python
from django.db import models

class Question(models.Model):
    question_text=models.CharField(max_length=200)
    pub_date=models.DateTimeField('date published')

    def __str__(self):
        return self.question_text

class Choice(models.Model):
    question=models.ForeignKey(Question,on_delete=models.CASCADE)
    choice_text=models.CharField(max_length=200)
    votes=models.IntegerField(default=0)    
    
    def __str__(self):
        return self.choice_text
```

모델에 커스테 메소드를 추가해 사용할 수 있다.

```python
import datetime
from django.db import models
from django.utils import timezone

class Question(models.Model):
    question_text=models.CharField(max_length=200)
    pub_date=models.DateTimeField('date published')

    def __str__(self):
        return self.question_text

    def was_published_recently(self):
        return self.pub_date >= timezone.now() - datetime.timedelta(days=1)

class Choice(models.Model):
    question=models.ForeignKey(Question,on_delete=models.CASCADE)
    choice_text=models.CharField(max_length=200)
    votes=models.IntegerField(default=0)    
    
    def __str__(self):
        return self.choice_text
```

```python
Python 3.8.1 (tags/v3.8.1:1b293b6, Dec 18 2019, 22:39:24) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license" for more information.
(InteractiveConsole)
>>> from polls.models import Choice, Question                 
>>> Question.objects.all()        
<QuerySet [<Question: What's up?>]>
>>> Question.objects.filter(id=1)
<QuerySet [<Question: What's up?>]>
>>> Question.objects.filter(question_text__startswith='What')
<QuerySet [<Question: What's up?>]>
>>> from django.utils import timezone
>>> current_year=timezone.now().year
>>> Question.objects.get(pub_date__year=current_year)
<Question: What's up?>
>>> Question.objects.get(id=2)
Traceback (most recent call last):
  File "<console>", line 1, in <module>
  File "C:\Users\wldnr\AppData\Local\Programs\Python\Python38-32\lib\site-packages\django\db\models\manager.py", line 82, in manager_method
    return getattr(self.get_queryset(), name)(*args, **kwargs)
  File "C:\Users\wldnr\AppData\Local\Programs\Python\Python38-32\lib\site-packages\django\db\models\query.py", line 415, in get
    raise self.model.DoesNotExist(
>>> Question.objects.get(pk=1)
<Question: What's up?>
>>> q=Question.objects.get(pk=1)
>>> q.was_published_recently()
True
>>> q.choice_set.all()
<QuerySet []>
>>> q.choice_set.create(choice_text='Not much',votes=0)
<Choice: Not much>
>>> q.choice_set.create(choice_text='The sky',votes=0)
<Choice: The sky>
>>> c=q.choice_set.create(choice_text='Jush hacking again',votes=0)
>>> c.question  
<Question: What's up?>
>>> q.choice_set.all()
<QuerySet [<Choice: Not much>, <Choice: The sky>, <Choice: Jush hacking again>]>
>>> q.choice_set.count()
3
>>> Choice.objects.filter(question__pub_date__year=current_year)
<QuerySet [<Choice: Not much>, <Choice: The sky>, <Choice: Jush hacking again>]>
>>> c = q.choice_set.filter(choice_text__startswith='Just hacking')
>>> c.delete()
(0, {'polls.Choice': 0})
```

## Django 관리자

### 관리자 생성

```
python manage.py createsuperuser
```

개발서버 시작 후 http://127.0.0.1:8000/admin/ 으로 접속해 admin 계정으로 로그인 할 수 있다.

### 관리사이트에 앱 추가

polls 앱의 admin.py 파일을 수정한다.

```python
from django.contrib import admin
from .models import Question

admin.site.register(Question)
```

## Django View

## 뷰 추가하기

* polls 앱의 views.py 수정

```python
from django.shortcuts import render
from django.http import HttpResponse

def index(request):
    return HttpResponse("Heelo world. You're at the polls index.")

def detail(request, question_id):
    return HttpResponse("You're looking at question %s." % question_id)

def results(request, question_id):
    response = "You're looking at the results of question %s."
    return HttpResponse(response % question_id)

def vote(request, question_id):
    return HttpResponse("You're voting on question %s." % question_id)
```

* urls 모듈로 연결

```python
from django.urls import path

from . import views

urlpatterns = [
    path('',views.index,name='index'),
    path('<int:question_id>/', views.detail, name='detail'),
    path('<int:question_id>/results/', views.results, name='results'),
    path('<int:question_id>/vote/', views.vote, name='vote'),
]
```

### 뷰 에서의 동작

    각 뷰는 HttpResponse 객체를 반환하거나 Http404와 같은 예외를 발생시킨다.

### 뷰에서 DB API 사용

```python
from .models import Question

def index(request):
    latest_question_list=Question.objects.order_by('-pub_date')[:5]
    output=', '.join([q.question_text for q in latest_question_list])
    return HttpResponse(output)
```

### 뷰 템플릿 사용

polls 디렉터리에 templates라는 디렉터리를 만들어 템플릿을 관리한다.

* polls/templates/polls/index.html

```html
{% if latest_question_list %}
<ul>
    {% for question in latest_question_list %}
    <li><a href="/polls/{{question.id}}">{{question.question_text}}</a></li>
    {% endfor %}
</ul>
{% else %}
<p>No polls are available.</p>
{% endif %}
```

* views.py에서 템플릿을 가져와 사용

```python
from django.template import loader
from .models import Question

def index(request):
    latest_question_list=Question.objects.order_by('-pub_date')[:5]
    template=loader.get_template('polls/index.html')
    context={
        'latest_question_list' : latest_question_list
    }
    return HttpResponse(template.render(context,request))
```

* render함수를 이용해 간단하게 표현

```python
from django.shortcuts import render
from .models import Question

def index(request):
    latest_question_list=Question.objects.order_by('-pub_date')[:5]
    context={
        'latest_question_list' : latest_question_list
    }
    return render(request,'polls/index.html',context)
```

### 404 에러 발생시키기

```python
from django.http import Http404
def detail(request, question_id):
    try:
        question=Question.objects.get(pk=question_id)
    except Question.DoesNotExist:
        raise Http404('Question does not exist')
    return render(request,'polls/detail.html',{'question':question})
```

* 더 간단하게 표현

```python
from django.shortcuts import render, get_object_or_404
def detail(request, question_id):
    question=get_object_or_404(Question,pk=question_id)
    return render(request,'polls/detail.html',{'question':question})
```

### 템플릿에서 하드코딩된 URL 제거

```html
<li><a href="{% url 'detail' question.id %}">{{question.question_text}}</a></li>
```
urls 모듈의 path 함수에서 정의한 이름을 사용해 URL을 불러온다.

### URL의 namespace 정하기

여러 개의 앱을 사용할 경우를 가정해 앱의 name을 정한다.

* polls의 urls.py 수정

```python
from django.urls import path

from . import views

app_name='polls'
urlpatterns = [
    path('',views.index,name='index'),
    path('<int:question_id>/', views.detail, name='detail'),
    path('<int:question_id>/results/', views.results, name='results'),
    path('<int:question_id>/vote/', views.vote, name='vote'),
]
```

* 템플릿 코드 수정

```html
<li><a href="{% url 'polls:detail' question.id %}">{{question.question_text}}</a></li>
```

## Form 작성

```html
<h1>{{ question.question_text }}</h1>

{% if error_message %}
<p><strong>
    {{error_message}}
</strong></p>
{% endif %}

<form action="{% url 'polls:vote' question.id %}" method="post">
    {% csrf_token %}
    {% for choice in question.choice_set.all %}
        <input type="radio" name="choice" id="choice{{forloop.counter}}" value="{{choice.id}}"/>
        <label for="choice{{forloop.counter}}">{{choice.choice_text}}</label><br/>
    {% endfor %}
    <input type="submit" value="Vote">
</form>
```

form으로 전송한 데이터를 처리할 vote view를 만든다

```python
def vote(request, question_id):
    question=get_object_or_404(Question,pk=question_id)
    try:
        selected_choice=question.choice_set.get(pk=request.POST['choice'])
    except (KeyError, Choice.DoesNotExist):
        return render(request,'polls/detail.html',{'question':question,'error_message':"You didn't select a choice",})
    else:
        selected_choice.votes+=1
        selected_choice.save()
        return HttpResponseRedirect(reverse('polls:results',args=(question.id,)))
```

choice를 request.POST['choice']로 받는다. 만약 choice가 없으면 KeyError가 일어난다.

reverse 함수를 통해 URL을 하드코딩 하지 않고 사용한다. reverse 함수는 /polls/question_id/results/ URL을 반환한다.

* result view 제작

```python
def results(request, question_id):
    question=get_object_or_404(Question,pk=question_id)
    return render(request,'polls/results.html',{'question':question})
```

* result 템플릿 제작

```html
<h1>{{question.question_text}}</h1>
<ul>
    {% for choice in question.choice_set.all %}
    <li>
        {{choice.choice_text}}--{{choice.votes}}
        vote{{choice.votes|pluralize}}
    </li>
    {% endfor %}
</ul>
```

## 제네릭 뷰 사용

### views.py 수정

```python
from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render, get_object_or_404
from .models import Choice, Question
from django.urls import reverse
from django.views import generic

class IndexView(generic.ListView):
    template_name="polls/index.html"
    context_object_name="latest_question_list"

    def get_queryset(self):
        return Question.objects.order_by('-pub_date')[:5]

def index(request):
    latest_question_list=Question.objects.order_by('-pub_date')[:5]
    context={
        'latest_question_list' : latest_question_list
    }
    return render(request,'polls/index.html',context)

class DetailView(generic.DetailView):
    model=Question
    template_name="polls/detail.html"

def detail(request, question_id):
    question=get_object_or_404(Question,pk=question_id)
    return render(request,'polls/detail.html',{'question':question})

class ResultView(generic.DetailView):
    model=Question
    template_name="polls/results.html"

def results(request, question_id):
    question=get_object_or_404(Question,pk=question_id)
    return render(request,'polls/results.html',{'question':question})

def vote(request, question_id):
    question=get_object_or_404(Question,pk=question_id)
    try:
        selected_choice=question.choice_set.get(pk=request.POST['choice'])
    except (KeyError, Choice.DoesNotExist):
        return render(request,'polls/detail.html',{'question':question,'error_message':"You didn't select a choice",})
    else:
        selected_choice.votes+=1
        selected_choice.save()
        return HttpResponseRedirect(reverse('polls:results',args=(question.id,)))
```

* model 속성을 사용해 각 제너릭 뷰에 어떤 모델이 적용될 것인지 알려준다.

* DetailView 제너릭 뷰는 URL에서 캡쳐 된 기본 키 값이 pk이기 떄문에 urls에서 수정한다.

* DetaulView 제너릭 뷰는 기본적으로 `<app name>/<model name>_detail.html` 템플릿을 사용한다. 이는 template_name 속성으로 수정할 수 있다.

* ListView 제너릭 뷰는 `<app name>/<model name>_list.html` 템플릿을 사용한다.

### urls.py 수정

```python
from django.urls import path

from . import views

app_name='polls'
urlpatterns = [
    path('',views.IndexView.as_view(),name='index'),
    path('<int:pk>/', views.DetailView.as_view(), name='detail'),
    path('<int:pk>/results/', views.ResultView.as_view(), name='results'),
    path('<int:question_id>/vote/', views.vote, name='vote'),
]
```

## 자동화 테스팅

### 자동화 테스트의 필요성

* 테스트를 통한 시간의 절약 : 특정 기능이 제대로 작동하는지 확인 함으로써 새로 발견된 문제의 원인을 확인 하는 시간이 절약됨

* 문제의 예방 : 애플리케이션의 목적 또는 의도된 동작, 정확한 기능을 알려주고 잘못된 부분을 알려줌

* 협업에서의 도움 : 동료가 개발한 코드의 정상동작 확인

### 테스트 작성

#### 버그 식별

Question.was_published_recently() 메서드는 Question이 어제 게시된 경우 True를 반환할 뿐만 아니라 **Question의 pub_date 필드가 미래로 설정되어 있을 때도 True를 반환한다.(버그)**

```python
>>> import datetime
>>> from django.utils import timezone
>>> from polls.models import Question
>>> future_question=Question(pub_date=timezone.now()+datetime.timedelta(days=30))
>>> future_question.was_published_recently()
True
```

#### 버그를 노출하는 테스트 작성

##### polls 어플리케이션의 tests 모듈 수정

```python
from django.test import TestCase

import datetime
from django.test import TestCase
from django.utils import timezone
from .models import Question

class QuestionModelTests(TestCase):

    def test_was_published_recently_with_future_question(self):
        time=timezone.now()+datetime.timedelta(days=30)
        future_question=Question(pub_date=time)
        self.assertIs(future_question
        .was_published_recently(),False)
```

##### 테스트 실행

```python
Creating test database for alias 'default'... # 테스트 데이터베이스 생성
System check identified no issues (0 silenced).
F
======================================================================
FAIL: test_was_published_recently_with_future_question (polls.tests.QuestionModelTests) # 테스트 중 오류 발생
----------------------------------------------------------------------
Traceback (most recent call last): # Trackback 출력
  File "C:\Users\wldnr\Documents\VisualCode\DjangoDocs\mysite\polls\tests.py", line 13, in test_was_published_recently_with_future_question
    self.assertIs(future_question
AssertionError: True is not False

----------------------------------------------------------------------
Ran 1 test in 0.001s

FAILED (failures=1)
Destroying test database for alias 'default'...
```

* manage.py test polls는 polls 애플리케이션에서 테스트를 찾는다.

* django.test.TestCase 클래스의 서브 클래스를 찾는다.

* 테스트목적의 DB를 생성한다.

* 이름이 test로 시작하는 메서드를 찾는다.

* 테스트를 실행한다.

* assertIs() 메서드를 사용해 False를 반환하기를 원함에도 실제로 True를 반환한다는 것을 발견하고 오류를 출력한다.

### 오류수정

model을 수정한다.

```python
    def was_published_recently(self):
        now=timezone.now()
        return now - datetime.timedelta(days=1) <= self.pub_date <= now
```

### 뷰 테스트

```python
>>> from django.test.utils import setup_test_environment
>>> setup_test_environment()
>>> from django.test import Client 
>>> client=Client()
>>> response=client.get('/')
Not Found: /
>>> response.status_code
404
>>> from django.urls import reverse
>>> response=client.get(reverse('polls:index'))
>>> response.status_code
200
>>> response.content
b'\n<ul>\n    \n    <li><a href="/polls/1/">What&#x27;s up?</a></li>\n    \n</ul>\n'
>>> response.context['latest_question_list'] 
<QuerySet [<Question: What's up?>]>
```

## 정적 파일 관리

### CSS 파일 생성

polls/static/polls/style.css를 생성한다.

```css
li a {
    color: green;
}
```

index.html을 수정한다.

```html
{% load static %}
<link rel="stylesheet" type="text/css" href="{% static 'polls/style.css' %}"
{% if latest_question_list %}
<ul>
    {% for question in latest_question_list %}
    <li><a href="{% url 'polls:detail' question.id %}">{{question.question_text}}</a></li>
    {% endfor %}
</ul>
{% else %}
<p>No polls are available.</p>
{% endif %}
```

## 관리자 페이지 커스터마이징

### 관리자 폼 커스터마이징

모델 페이지의 필드를 수정할 수 있다.

```python
from django.contrib import admin
from .models import Question

class QuestionAdmin(admin.ModelAdmin):
    fieldsets = [
        (None,               {'fields': ['question_text']}),
        ('Date information', {'fields': ['pub_date']}),
    ]

admin.site.register(Question,QuestionAdmin)
```

#### 객체 추가

```python
from .models import Question,Choice
admin.site.register(Choice)
```


# Model

* database에 대한 상세한 설정은 config/database.yml에서 가능하다.

### Model 생성

```
rails generate model [Model 이름] [컬럼들]
```

초보자는 그냥 Model 이름까지만 치고 Migration 파일에 들어가 직접 설정하는걸 추천한다.

db/migrate 폴더에 들어가면 생성한 파일이 있다.

아래 파일처럼 Model파일이 생성이 되어있을텐데, 사용할 컬럼을 넣어주면 된다.

예를들어 string 자료형 userName 컬럼은 t.string :userName 이런식으로 넣어준다.

null: false 는 null 입력을 불허하는 옵션이다.

참고로 Foreign key 설정, unique key 설정 등은 migration 후 설정할 수 있다.

```ruby
class CreateUsers < ActiveRecord::Migration[6.1]

  def change
    create_table :users do |t|
    # 컬럼
    #   t.string :firstName, null: false
    #   t.string :lastName, null: false
    #   t.string :email, null: false
    #   t.string :password, null: false
    #   t.string :contry
    #   t.timestamps
    end
  end
end
```

아래의 명령어를 치면 db가 성공적으로 migration된다.
```
rake db:migrate
```

db를 수정하고 싶으면 아래 명령어를 치고 다시 만들면 된다.
```
rake db:drop
````

## Model 설정

db를 migration 했으면 app/model 폴더 안에 해당 Model이 생성되어있다.

여기서 표현관계를 지정할 수 있다.

1. 1:M 관계
```ruby
class User < ApplicationRecord
    has_many :projects, dependent: :destroy
end
```
dependent: :destroy는 cascade 설정과 동일하다.


2. M:1 관계
```ruby
class Project < ApplicationRecord
    belongs_to :user
end
```

3. M:N 관계
```ruby
class Post < ApplicationRecord
	has_and_many :tags, :through
end
```

제약조건 명시도 가능하다.

1. unique

```ruby
class User < ApplicationRecord
    validates_uniqueness_of :email
end
```

2. validates
```ruby
class User < ApplicationRecord
    validates :firstName, :lastName, :email, :password, presence: true
end
```


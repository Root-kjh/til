# Route

Route 설정은 config/routes.rb에서 가능하다.

## 기본 Route 설정

```ruby
Rails.application.routes.draw do
    post    "/users/signup",  to: "users#signup"
    post    "/auth/signin",   to: "users#signin"
  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html
end
```

위와 같은 형식으로 설정한다.

[HTTP Method] ["URL 경로"] to: ["ruby파일#함수"]

## 그 외 옵션

* namespace
>users do 안에 있는 설정들은 경로의 맨 앞에 "/users" 가 붙게 되고, 해당 controller 파일은 users 폴더로 넣는다.

```ruby
Rails.application.routes.draw do
  
    namespace :users do
        # users View
        post    "/signup",  to: "users#signup"
        post    "/signin",   to: "users#signin"
    end

  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html
end
```

* scope module
>scope module: :xxx의 xxx에 해당되는 부분이 controller명 앞 디렉토리 path로 추가됨

```ruby
scope module: :admin do
  resources :users
do
```

* scope
>url 부분에만 패스가 추가됨

```ruby
namespace :admin do
  resources :users
do
```

* resouces, resouce

아래와 같이 입력하고 커맨드 rake routes를 치면 자동으로 생성된 routes가 나온다.

```ruby
Rails.application.routes.draw do
    resources :users
  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html
end
```
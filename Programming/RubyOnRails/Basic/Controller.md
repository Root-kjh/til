# Controller

* Controller 파일은 app/controllers에 있다.

## Basic

* 변수는 @변수명 으로 지정한다.



## Params

파라미터는 두가지 방법으로 가져올 수 있다.

1. 일반 파라미터

```ruby
def signup
    @userName = params[:userName]
end
```

2. Strong Parameters
>컨트롤러가 받은 변수에 대해 갱신을 허가하고, 금지할지 명시적으로 결정하기 위해 사용한다.

매개변수에 permit, required를 지정할 수 있으며, permit은 사용이 허용되는 파라미터, required는 해당 키값이 있어야 하는 파라미터를 말한다.(이건 나도잘 모르겠다 이후 내용 추가바람)

규칙이 지켜지지 않으면 400 bad request를 돌려줄 수 있다.


```ruby
def signup
    @user = (user_params)
end

private
    def user_params
        params.require(:userName, :password).permit(:age, :email)
    end
```

검색 중 Strong Parameters라는 기능이 루비 온 레일즈에 기본 모듈로 제공되며 사용을 권장하게된 배경을 찾았는데 꽤 흥미로워 기록한다.
```
한 때 레일즈 개발자 사이에 떠들썩한 이슈가 있었는데, 바로 Egor Homakov라는 사람이 Github의 보안취약점을 지적한 일입니다.

이슈가 된 이유는 간단합니다. 해킹 방법이 너무 간단하고 치명적이었기 때문입니다. 그의 포스트 내용은 아래와 같습니다.

I simply added a field to Public key update form, where USER_ID = 4223 (from https://api.github.com/users/rails).

Backend didn't whitelist accessible attributes and had something like this: @key = PublicKey.find(params[:id]) @key.update_attributes(params[:public_key]) #Oh no! We passed public_key[user_id] of our victim!

Now our victim (Rails) has our public key associated with their account. You can read/write in any public/private repo on github.

이로 인해 레일즈를 사용하는 모든 개발자들이 whitelist에 대해 심각성을 느끼게 되었고, Rails4에서부터 Strong Parameters를 기본 기능으로 제공하기 시작했습니다.
```
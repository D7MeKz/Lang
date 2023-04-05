package main

import (
	"fmt"
	// text/template"
	// htemplate "image/template" // Template 명이 같을 경우 별도의 이름을 지정할 수 있다.
	_ "database/sql" // package를 사용하지 않으면 에러가 발생하기 때문에 사용하지 않는 경우 _을 지정하자.
	// 모듈 내 나의 패키지
	"package/usepkg/custompkg"
)

func main() {
	fmt.Print("Hello WOrld!")
	custompkg.PrintCustom()
}

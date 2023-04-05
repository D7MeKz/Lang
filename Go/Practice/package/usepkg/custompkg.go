package cumstompkg

import "fmt"

// 변수 초기화
var (
	d = 3
	a = foo() // a가 먼저 있다면 d가 우선 초기화되고 나서 a가 초기화된다.
)

// 함수 초기화
func init() {
	d++
	fmt.Print("Init Function")
}

func foo() int {
	d++
	fmt.Printf("Hello: %d", d)
	return d
}

func PrintCustom() {
	fmt.Println("This is Custom Package!!")
}

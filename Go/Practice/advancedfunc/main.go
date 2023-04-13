package main

import (
	"fmt"
	"os"
)

// 가변 함수
// slice type []int
// 단 동일한 타입만  ...를 사용한다.
func sum(nums ...int) int {
	sum := 0

	for _, v := range nums {
		sum += v
	}
	return sum
}

// Go는 함수 포인터가 있다.
// 즉 함수를 변수처럼 사용할 수 있다. (물론 return도 가능하다. )
func add(a, b int) int {
	return a + b
}

func mul(a, b int) int {
	return a * b
}

func getOperator(op string) func(int, int) int {
	if op == "+" {
		return add
	} else if op == "*" {
		return mul
	} else {
		return nil
	}
}

// OS 리소스를 사용할 경우 프로그램을 종료하고 바로 OS에게 반납해야 한다.
// 이때 사용되는 것이 defer 명령어이다.
func main() {
	fmt.Println(sum(1, 2, 3, 4, 5))

	f, err := os.Create("./test.txt") // 파일 생성
	if err != nil {
		fmt.Print("Error")
		return
	}

	// defer은 3->2->1 역순으로 호출된다.
	defer fmt.Println("반드시 호출됩니다.") // 1
	defer f.Close()                 // 2
	defer fmt.Println("파일을 닫았습니다.") // 3

	fmt.Println("이 파일은 hello world를 씁니다.")
	fmt.Fprintln(f, "Hello World?")

	var operator func(int, int) int // 선언
	operator = getOperator("+")
	fmt.Println(operator(4, 5)) // 함수 타입 변수로 호출

}

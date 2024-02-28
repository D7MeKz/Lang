package main

import (
	"fmt"

	"golang.org/x/exp/constraints"
)

// 타입 제한 설정
type Integer interface {
	int8 | int16 | int32 | int64 | int
}

// ~ : 해당 타입을 기본으로 하는 모든 별칭 타입들까지 포함
type Float interface {
	~float32 | ~float64
}

// a,b 모두 동일한 변수 타입을 가져야 한다.
func add[T constraints.Integer | constraints.Float](a, b T) T {
	return a + b
}

// interface를 활용해 타입을 제한하여 제너릭을 수행할 수 있음
func add2[T Integer](a, b T) T {
	return a + b
}

// 이럴 경우 T1, T2의 타입이 무조건 같을 필요가 없다.
func Print[T1 any, T2 any](a T1, b T2) {
	fmt.Println(a, b)
}

// 다른 방식으로 interface를 사용할 수 있다.
func Print2(a, b interface{}) {
	fmt.Println(a, b)
}

func main() {
	var a int = 1
	var b int = 1
	fmt.Println(add(a, b))

	var c float32 = 1.2
	var d float32 = 1.5
	fmt.Println(add(c, d))
}

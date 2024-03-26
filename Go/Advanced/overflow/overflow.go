package main

import "math"

func AddInt(a, b int) int {
	if a > math.MaxInt-b {
		panic("int Overflow")
	}
	return a + b
}

func MultiplyInt(a, b int) int {
	if a == 0 || b == 0 {
		return 0
	}

	result := a * b
	// 예외 케이스. 만약에 result/b != a 수행 시 int overflow로 지정된다.
	if a == 1 || b == 1 {
		return result
	}
	if a == math.MaxInt || b == math.MaxInt {
		panic("int Overflow")
	}
	if result/b != a {
		panic("int Overflow")
	}
	return result
}

func main() {
	a := math.MaxInt - 5
	b := 3

	AddInt(a, b)
	MultiplyInt(a, b)

}

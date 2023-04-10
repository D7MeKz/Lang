package main

import "fmt"

type myInt int

func (a myInt) add(b int) int {
	return int(a) + b
}

func main() {
	var a myInt = 10
	// 일반적인 function의 특징
	// 소속감 -> 객체지향적 설계
	fmt.Println(a.add(30))

}

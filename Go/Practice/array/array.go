package main

import "fmt"

const num int = 5 // 배열의 개수는 무조건 상수다

func main() {
	a := [num]int{1, 2, 3, 4, 5}
	b := [...]int{1, 2, 3}

	fmt.Print("A array\n")
	for i := 0; i < len(a); i++ {
		fmt.Println(i)
	}

	fmt.Print("B array\n")
	// range는 인덱스와 원솟값을 출력
	for i, v := range b {
		fmt.Println(i, v)
	}
}

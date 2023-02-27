package main

import "fmt"

func main() {
	// flag 데이터를 사용하기 번거로울때
	// Label를 사용한다.

	a := 1
	b := 1

ThisIsLabel:
	for i := 0; i < 10; i++ {
		a += 1
		b += 1

		if a+b == 10 {
			fmt.Printf("a: %d, b: %d", a, b)
			break ThisIsLabel
		}
	}
}

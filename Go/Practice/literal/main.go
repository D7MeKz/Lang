package main

import "fmt"

type opFunc func(a, b int) int

func getOperator(op string) opFunc {
	if op == "+" {
		return func(a, b int) int {
			// 리터럴 사용
			return a + b
		}
	} else {
		return nil
	}
}

func main() {
	fn := getOperator("*")
	result := fn(3, 4)
	fmt.Println(result)
}

package main

import "fmt"

func main() {
	s1 := []int{1, 2, 3}
	fmt.Print(s1)

	s2 := change(s1[:2:2])
	fmt.Print(s2)

}

func change(s []int) []int {
	return append(s, 10)

}

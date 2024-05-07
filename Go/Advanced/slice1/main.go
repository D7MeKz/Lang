package main

import "fmt"

func main() {
	// Wrong
	src := []int{1, 2, 3}
	var dst []int
	copy(dst, src) // 대상 슬라이스, 원본 슬라이스
	fmt.Print(dst) // return []

	// Solution 1
	dst2 := make([]int, len(src))
	copy(dst2, src)
	fmt.Print(dst2) // return [1 2 3]

	// Solution 2
	dst3 := append([]int(nil), src...)
	fmt.Print(dst3)

}

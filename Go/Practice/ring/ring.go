package main

import (
	"container/ring"
	"fmt"
)

func main() {
	r := ring.New(5)
	n := r.Len()

	for i := 0; i < n; i++ {
		r.Value = 'A' + i
		r = r.Next()
	}

	for j := 0; j < n; j++ {
		fmt.Printf("%c", r.Value)
		r = r.Next()
	}

	fmt.Println()

	// 역순
	// 저장할 개수가 고정되고, 오래된 요소는 지워도 되는 경우에 적합 
	// ex) 고정된 크기의 리
	for j := 0; j < n; j++ {
		fmt.Printf("%c", r.Value)
		r = r.Prev()
	}
}

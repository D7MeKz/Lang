package main

import (
	"container/list"
	"fmt"
)

// 리스트는 불연속 데이터를 저장한다는 점에서 배열과 다르다.
// 양방향 리스트
func main() {
	v := list.New()
	e4 := v.PushBack(4)
	e1 := v.PushFront(1)
	v.InsertBefore(3, e4) // e4 요소 앞에 삽입
	v.InsertAfter(2, e1)  // e1 요소 뒤에 삽입

	for e := v.Front(); e != nil; e = e.Next() {
		fmt.Print(e.Value)
	}

}

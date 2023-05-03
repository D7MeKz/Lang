package main

import (
	"container/list"
	"fmt"
)

type Queue struct {
	v *list.List
}

func (q *Queue) Push(val interface{}) {
	q.v.PushBack(val)
}

// 빈 인터페이스를 적용해서 모든 타입을 가져올 수 있도록 했다.
func (q *Queue) Pop() interface{} {
	front := q.v.Front()
	if front != nil {
		return q.v.Remove(front)
	}
	return nil
}

func NewQueue() *Queue {
	return &Queue{list.New()}
}

func main() {
	queue := NewQueue()

	for i := 1; i < 5; i++ {
		queue.Push(i)
	}

	v := queue.Pop()
	for v != nil {
		fmt.Printf("%v ->", v)
		v = queue.Pop()
	}

}

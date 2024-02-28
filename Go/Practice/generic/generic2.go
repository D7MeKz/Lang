package main

import (
	"fmt"
	"hash/fnv"
)

// 타입 제한 정의
// Method 제한
type ComparableHasher interface {
	comparable
	Hash() uint32
}

type MyString string

func (s MyString) Hash() uint32 {
	h := fnv.New32a()
	h.Write([]byte(s))
	return h.Sum32()
}

// 타입 제한은 제네릭 프로그래밍의 타입 파라미터에서만 사용할 수 있다.
// 일반 인터페이스처럼 사용할 수 없다.
// 타입 제한을 포함한 인터페이스는 반드시 타입 파라미터로 정의되어야 한다.
func Equal[T ComparableHasher](a, b T) bool {
	if a == b {
		return true
	}
	return a.Hash() == b.Hash()
}

func main() {
	var str1 MyString = "Hello"
	var str2 MyString = "World"
	fmt.Println(Equal(str1, str2))
}

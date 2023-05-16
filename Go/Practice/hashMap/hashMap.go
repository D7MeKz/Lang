package main

import "fmt"

const M = 10

func hash(d int) int {
	return d % M
}

// 키값: 해시값 Map을 생성한다고 가정해보자.
func main() {
	m := [M]int{}

	m[hash(23)] = 10
	// 해시 충돌이라는 치명적인 단점, mod 연산을 하면 23과 33가 같기 때문에 값이 덮어쓰이는 문제 발생
	m[hash(259)] = 50

	// 해시 충돌은 리스트를 통해 해키값
	fmt.Printf("%d = %d\n", 23, m[hash(23)])
}

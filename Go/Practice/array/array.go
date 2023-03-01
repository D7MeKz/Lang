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
	// 변수를 쓰지 않으면 컴파일 에러가 발생하므로,
	// 인덱스를 쓰지 않는다면 _로 무효화시킨다.
	for i, v := range b {
		fmt.Println(i, v)
	}

	var arr1 = [5]int32{1, 2, 3, 4, 5}
	fmt.Print(arr1)
}

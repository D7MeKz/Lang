package main

import "fmt"

func main() {
	// ! 슬라이스와 배열의 차이점은 크기가 미리 지정되냐의 유무이다.
	// ! 즉 슬라이스의 경우 크기가 우선 지정되지 않고 배열은 크기가 지정되어야 한다.
	// !!!! 슬라이스는 값을 포인터로 가르킨다! 이런 점에서 배열과는 다르다!!!!!

	// 5:2 Index[5] = 2라는 의미
	var slice1 = []int{1, 5: 2, 3} // 슬라이스 선언
	var slice2 = make([]int, 3)    // 3개 크기의 배열 선언, Default = 0

	// 맨 끝자락에 5 추가
	slice1 = append(slice1, 5)
	slicing1 := slice2[:2]
	// 총 4개 인덱스 중에서만 슬라이싱을 하겠다.
	slicing2 := slice2[:2:3]
	for i, v := range slice1 {
		fmt.Printf("%d %d\n", i, v)
	}

	for i, v := range slicing1 {
		fmt.Printf("%d %d\n", i, v)
	}

	// slice 값을 복사하려면 일리리 순회해서 해야하지만
	// 간단한 방법도 존재한다.
	slice_copy := append([]int{}, slice1...)
	// copy 함수를 사용하는 방법도 존재한다.
	// 복사된 요소의 크기를 return
	// 적은 개수만큼 복사된다.
	cnt1 := copy(slice_copy, slice1)

	// Go 에서의 요소 삭제, 및 추가는 사이에 값을 추가 및 삭제 후 맨 뒤 요소를 추가 및 삭제하는
	// 과정이 필요하다.
	// idx 요소 삭제
	slice1 = append(slice1[:1], slice1[2:]...)

}

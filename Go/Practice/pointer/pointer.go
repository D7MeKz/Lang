package main

import "fmt"

// 포인터는 왜 쓸까?
// 메모리 낭비를 최소화하기 위해서이다.
type Data struct {
	value int
	data  [100]int
}

// 값에 의한 복사
func ChangeData(arg Data) {
	arg.value = 999
	arg.data[99] = 999
}
func ChangeWithPointer(arg *Data) {
	arg.value = 888
	arg.data[99] = 888
}

func main() {
	// 포인터의 개념은 C와 동일하다.
	var a int = 10
	var b int = 20
	var c int = 30

	var p1 *int = &a
	var p2 *int = &b
	var p3 *int = nil // Default
	p3 = &c
	fmt.Printf("p1 = %v, p2 = %v, P3 = %v\n", p1, p2, p3)

	var data Data
	var data2 Data
	ChangeData(data) // 출력값은 초기값인 0으로 지정된다.
	ChangeWithPointer(&data2)

	fmt.Printf("%d %d\n", data.value, data.data[99])
	fmt.Printf("%d %d", data2.value, data2.data[99])

	// 인스턴스란 메모리에 할당된 데이터의 실체이다.
	// 인스턴스가 1개다.
	// datat 1, 2, 3이 인스턴스 Data 하나만을 가리킨다.
	var data1 *Data = &Data{}
	var data2 Data = data1
	var data3 Data = *data1

	// 값에 의한 복사는 복사한 개수 만큼 인스턴스가 밸생된다.
	// Go는 가비지 컬렉터를 가지고 있다.
	// 컴파일러가 일정 간격으로 메모리에서 쓸데없는 데이터를 청소한다.
	// 외부 공개 여부에 따라서 힙 or 스택 영역에 할당할지 결정한다.
}

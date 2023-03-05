package main

import (
	"fmt"
	"unsafe"
)

type House struct {
	Address string
	Size    int
	Price   float64
	Type    string
}

type User struct {
	Id  int16
	Id2 float64
}

// 크기가 낮은것부터 배치해야 메모리를 절약할 수 있다.
type Padding struct {
	A int8
	B int8
	C float64
}

func main() {
	// * 선언시 자동으로 변수의 값을 초기화시킨다.
	var house House
	house.Address = "Gwan.."
	house.Size = 5
	house.Price = 2.00
	house.Type = "H.."

	var house2 House = House{"G", 2, 3.12, "H"}
	fmt.Println("House address: ", house2.Address)

	user := User{12, 2.54}
	// 메모리 정렬 때문에 원래 10바이트 -> 16 바이트로 변경되었다.
	fmt.Println("Bytes: ", unsafe.Sizeof(user))

	padding := Padding{1, 2, 3.0}
	fmt.Println("Bytes Padding: ", unsafe.Sizeof(padding))
}

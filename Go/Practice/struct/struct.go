package main

import "fmt"

type House struct {
	Address string
	Size    int
	Price   float64
	Type    string
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

}

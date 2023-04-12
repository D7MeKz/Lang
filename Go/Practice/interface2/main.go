package main

import "fmt"

// 빈 인터페이스를 인수로 받는다.
func PrintVal(v interface{}) {
	// ()은 구체화된 타입 변환
	switch t := v.(type) {
	case int:
		fmt.Printf("int : %d\n", int(t))
	case float64:
		fmt.Printf("flat64 : %f\n", float64(t))
	case string:
		fmt.Printf("String : %s\n", string(t))
	default:
		fmt.Print("Not supported.\n")
	}
}

type Student struct {
	Age int
}

func main() {
	PrintVal(Student{15})
}

// 인터페이스 간의 변환이 존재한다.
// 다만 유의해야할 점은 변환하고자 하는 인터페이스의 메소드를 잘 확인해야 한다.
// 가리키는 타입과 메소드의 유무 등을 잘 고려해야 한다.

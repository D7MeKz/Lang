package main

// 표준 입출력을 다루는 패키지
import "fmt"

// package 전역 변수
var packVar int8 = 10

func main() {
	// * 메모리 공간 만들고 -> 해당 변수로 지칭 -> 값 복사
	// C++ 못지 않게 많은 숫자 타입을 가지고 있다.
	var a int8 = 10
	var b int = 20
	// CamelCase variable

	var sample1 int = 20
	var sample2 = 30
	sample3 := 40 // 선언 대입문: var 키워드와 타입을 생략
	fmt.Println("Hello World", a, b, sample1, sample2, sample3)

	// * Go는 최강강강강 타입 언어임
	iData := 5
	i16Data := 3456
	fData := 2.5

	iAns := iData * int(fData)
	fmt.Println(iAns) // 5 * 2

	/*
		상위 8비트가 날라감
		int8 -128 ~ 128
	*/
	iAns2 := int8(i16Data)
	fmt.Println(iAns2)

	fmt.Println(packVar)

	// * float32의 경우에는 소수부가 8비트로 정해져 있다.
	// * float64 -> 15비트
	var fSam1 float32 = 123.456 // * 0.123456e+03, 소수부: 123456, 지수부: 3
	fmt.Println(fSam1)

}

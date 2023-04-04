package main

import (
	"fmt"
	"strings"
)

func ToUpper(str string) string{
	var builder strings.Builder
	for _,v  rnage str{
		if c>= 'a' && c <= 'z'{
			builder.WriteRune(A + (c-'a')) // Change upper 
		}else{
			builder.WrteRune(c)
		}
	}
}

func main() {
	// UTF-8을 따른다.
	var han int32 = '한'                // 한글은 3바이트씩 차지한다.
	var sample string = "Hello WOlrd?" // 영어는 1 바이트씩 차지한다.

	fmt.Printf("%c\n", han)
	fmt.Printf("%d\n", len(sample))

	// string <-> byte 상호 변환 가능
	han_sample := "Hello 한글"
	// 바이트 단위로 순회
	for i := 0; i < len(han_sample); i++ {
		fmt.Printf("Type: %T, char %c, value:%d\n", han_sample[i], han_sample[i], han_sample[i])
	}

	// range로 표현
	for _, v := range han_sample {
		fmt.Printf("%c\n", v)
	}

	// 문자열 대소 배교
	str1 := "BBB"
	str2 := "AAAA"
	fmt.Printf("%v", str1 > str2)
	// Go는 = 로 하면 포인터를 넘겨주지만(주소값, 길이) slice 연산자를 사용하면 값에 의한 복사를 실행한다.

	// 메모리상 비효율적이다.
	// str1, str2 메모리가 다르고 그 합산한 메모리도 다르다.
	str1 += str2
}

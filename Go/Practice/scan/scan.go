package main

import (
	"bufio"
	"fmt"
	"os"
)

/*
* Go에서 표준 입력 스트림은 한글자씩 읽어 오류를 판별한다.(FIFO 구조 사용)
* 그러나 표준 입력 스트림을 읽는 도중에서 Scan과 관련된 함수를 다시 사용하게 된다면 새로운 스트림을 선언하는게 아니라 기존에 있는 스트림을 사용하게 된다.
* 그러므로 새롭게 선언하고 싶다면 표준 입력 스트림을 지우는 작업이 필요하다.
 */
func main() {
	stdin := bufio.NewReader(os.Stdin) // 표준 입력을 읽는 객체
	var a int8
	var b int8

	// ! Get Error Code!
	// Standard input stream : FIFO
	n, err := fmt.Scanln(&a, &b)
	if err != nil {
		fmt.Printf("Error: %d %s", n, err)
		stdin.ReadString('\n') // 표준 입력 스트림 지우기
	} else {
		fmt.Printf("%d", n)
	}

}

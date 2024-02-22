package main

import (
	"fmt"
	"os"
)

func main() {
	f, err := os.Create("text.txt") // create file
	if err != nil {
		fmt.Println("Failed to create file")
		return
	}

	defer fmt.Println("반드시 호출된다.")
	defer f.Close()
	defer fmt.Println("호출 종료")

	fmt.Println("파일에 Hello World를 쓴다.")
	fmt.Fprintln(f, "Helloworld")

}

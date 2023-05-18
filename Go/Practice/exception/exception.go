package main

import (
	"bufio"
	"fmt"
	"os"
)

// 에러를 반환하는 식으로 !!

func ReadFile(filename string) (string, error) {
	file, err := os.Open(filename)
	if err != nil {
		return "", err
	}
	defer file.Close()
	rd := bufio.NewReader(file)
	line, _ := rd.ReadString('\n') // 한줄씩 읽기
	return line, nil
}

func WriteFile(filename string, line string) error {
	file, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer file.Close()
	_, err = fmt.Fprintln(file, line)
	return err
}

const filename string = "data.txt"

func main() {
	line, err := ReadFile(filename)
	if err != nil {
		err = WriteFile(filename, "This is a pen")
		// 에러 메세지는 직접
		if err != nil {
			fmt.Println("Fail to make file", err)
			return
		}
		line, err = ReadFile(filename)
		if err != nil {
			fmt.Println("Faile to read", err)
			return
		}
	}
	fmt.Println("File : ", line)
}

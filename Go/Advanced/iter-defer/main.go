package main

import (
	"os"
)

func readFiles(ch <-chan string) error {
	for path := range ch {
		err := func() error {
			file, err := os.Open(path)
			if err != nil {
				return err
			}

			st, _ := os.ReadFile(file.Name())
			println(string(st))
			// defer의 경우 함수가 종료되고 실행된다.
			// 따라서 파일을 바로 닫고 싶다면 파일을 닫아주는 별도의 함수를 넣거나
			// Closer를 사용하면 된다.
			defer file.Close()

			// Do something with file
			return nil
		}()

		if err != nil {
			return err
		}
	}
	return nil
}

func main() {
	ch := make(chan string)
	go func() {
		defer close(ch)
		ch <- "a.txt"
		ch <- "b.txt"
	}()

	_ = readFiles(ch)
}

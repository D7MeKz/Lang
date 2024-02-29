package main

import "fmt"

// 에러 구조체 선언
type PasswordError struct {
	Len        int
	RequireLen int
}

// Error 메서드 -> PasswordError를 error 인터페이스로써 사용 가능
func (err PasswordError) Error() string {
	return "암호 길이가 짧습니다."
}

func RegisterAccount(name, password string) error {
	if len(password) < 8 {
		return PasswordError{len(password), 8}
	}
	return nil
}

func main() {
	err := RegisterAccount("myId", "myPw")
	if err != nil {
		if errorInfo, ok := err.(PasswordError); ok { // return Interface
			fmt.Printf("%v Len:%d RequireLen: %d\n", errorInfo, errorInfo.Len, errorInfo.RequireLen)
		}
	} else {
		fmt.Println("Success")
	}
}

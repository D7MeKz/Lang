package fedex

import "fmt"

// 덕 타이핑
// 덕 타이핑이 없었더라면 타입 선언 시 인터페이스 구현 여부를 명시해야 한다.
type FedexSender struct {
}

func (f *FedexSender) Send(parcel string) {
	fmt.Printf("Fedex sends %v parcel\n", parcel)
}

// 인터페이스는 메서드의 포함 여부만 확인한다.

package main

import (
	"interface/fedex"
	"interface/koreapost"
)

// 인터페이스 정의
// fedex, koreapost 둘 다 send 메서드를 가지고 있기 때문에
// Sender Interface에 속한다.
type Sender interface {
	Send(parcel string)
}

func SendBook(name string, sender Sender) {
	sender.Send(name)
}

func main() {
	sender := &fedex.FedexSender{}
	SendBook("little prince", sender)
	SendBook("Tom and jerry", sender)

	koreapostSender := &koreapost.PostSender{}
	SendBook("Hi?", koreapostSender)

}

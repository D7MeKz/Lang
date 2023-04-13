package main

import (
	"interface/fedex"
	"interface/koreapost"
)

// 인터페이스 정의
// fedex, koreapost 둘 다 send 메서드를 가지고 있기 때문에
// Sender Interface에 속한다.
// 클래스의 추상화 기능 제공
// 추상화 계층을 이용해 의존 관계를 끊는 것을 디커플링이라고 한다.
// 의존성을 낮을수록 좋다.
// 내부 구현은 알 수 없으나 메서드의 집합만 알 수 있다. -> 관계로 상호작용한다.
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

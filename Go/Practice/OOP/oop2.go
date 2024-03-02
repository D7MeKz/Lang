package main

import "fmt"

// Event, EventListener는 의존 관계를 가진다.
// Interface
type Event interface {
	Register(EvenListener)
}

type EvenListener interface {
	OnFire()
}

// Sub Class
type Mail struct {
	listener EventListener
}

// Implementation
func (m *Mail) Register(listener EvenListener) {
	m.listener = listener
}

func (m *Mail) OnRecv() {
	m.listener.OnFire()
}

type Alarm struct {
}

// Implementation
func (alarm Alarm) OnFire() {
	fmt.Print("Alarm!")
}

func main() {
	var mail = &Mail{}
	var listener EvenListener = &Alarm{}

	mail.Register(listener)
	mail.OnRecv()
}

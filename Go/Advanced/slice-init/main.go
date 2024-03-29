package main

type Foo struct {
	Name string
}

type Bar struct {
	Name string
}

func fooToBar(foo Foo) Bar {
	return Bar{Name: foo.Name}
}

// foos의 길이만큼 슬라이스 용량 지정
func convertCapacity(foos []Foo) []Bar {
	n := len(foos)
	bars := make([]Bar, 0, n)
	for _, foo := range foos {
		bars = append(bars, fooToBar(foo))
	}
	return bars
}

// foos의 길이만큼 슬라이스 길이 지정
func convertLength(foos []Foo) []Bar {
	n := len(foos)
	bars := make([]Bar, n)
	for i, foo := range foos {
		bars[i] = fooToBar(foo)
	}
	return bars
}

func main() {

}

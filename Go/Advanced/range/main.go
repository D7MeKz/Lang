package main

import "fmt"

func main() {
loop:
	for i := 0; i < 3; i++ {
		fmt.Printf("%d\n", i)
		switch i {
		case 2:
			break loop
		}
	}
}

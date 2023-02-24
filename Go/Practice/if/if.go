package main

import "fmt"

func getMyAge() (int, bool) {
	return 24, true
}

func main() {

	if age, status := getMyAge(); status {
		fmt.Printf("Age: %d", age)
	} else {
		fmt.Print("False....")
	}
}

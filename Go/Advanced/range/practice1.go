package main

import "fmt"

func Practice1() {
	ch1 := make(chan int, 3)
	go func() {
		ch1 <- 0
		ch1 <- 1
		ch1 <- 2
		close(ch1)
	}()

	ch2 := make(chan int, 3)
	go func() {
		ch2 <- 10
		ch2 <- 11
		ch2 <- 12
		close(ch2)
	}()

	ch := ch1
	for v := range ch {
		fmt.Println(v)
		ch = ch2
	}
}

func Practice2() {
	a := [3]int{1, 2, 3}
	for i, v := range a {
		a[2] = 10
		if i == 2 {
			fmt.Println(v)
		}
	}
}

func Practice2Fix1() {
	a := [3]int{1, 2, 3}
	for i, _ := range a {
		a[2] = 10
		if i == 2 {
			fmt.Println(a[i])
		}
	}
}
func Practice2Fix2() {
	a := [3]int{1, 2, 3}
	for i, v := range &a {
		a[2] = 10
		if i == 2 {
			fmt.Println(v)
		}
	}
}

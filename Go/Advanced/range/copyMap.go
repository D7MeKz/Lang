package main

import "fmt"

func copyMap(m map[int]bool) map[int]bool {
	m2 := make(map[int]bool)
	for k, v := range m {
		m2[k] = v
	}
	return m2
}

func Practice3() {
	var m = map[int]bool{
		1: true,
		2: false,
		3: true,
	}
	m2 := copyMap(m)

	for k, v := range m {
		m2[k] = v
		if v {
			m2[k+10] = true
		}
	}

	fmt.Println(m2)

}

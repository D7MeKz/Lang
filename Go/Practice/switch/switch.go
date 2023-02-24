package main

import "fmt"

type ColorType int

const (
	Red ColorType = iota
	Blue
	Green
)

func colorToString(color ColorType) string {
	switch color {
	case Red:
		return "Red"
	case Blue:
		return "Blue"
	case Green:
		return "Green"
	default:
		return "Nothing..."
	}
}

func main() {

	var favoriteColor int

	fmt.Scanln(&favoriteColor)
	fmt.Println(colorToString(ColorType(favoriteColor)))
}

package main

import (
	"testing"
)

func TestSquare(t *testing.T) {
	rst := square(9)
	if rst != 81 {
		t.Errorf("Error: %d", rst)
	}
}

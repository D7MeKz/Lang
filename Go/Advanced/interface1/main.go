package main

import "fmt"

type Stringer interface {
	String() string
}

type Student struct {
	Name string
}

func (s Student) String() string {
	return s.Name
}

type Teacher struct {
	Name string
}

func (t Teacher) String() string {
	return t.Name
}

func PrintStudent(stringer Stringer) {
	if c, ok := stringer.(Student); ok {
		fmt.Printf("Student Name is %s", c.Name)
	}
}

func main() {
	student := Student{Name: "Student"}
	PrintStudent(student)

}

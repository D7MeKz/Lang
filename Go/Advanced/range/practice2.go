package main

import "fmt"

type Customer struct {
	ID      string
	Balance float64
}

type Store struct {
	m map[string]*Customer
}

func (s *Store) Add(customers []Customer) {
	for _, customer := range customers {
		fmt.Printf("%p\n", &customer)
		s.m[customer.ID] = &customer
		fmt.Println(s.m[customer.ID])
	}
}

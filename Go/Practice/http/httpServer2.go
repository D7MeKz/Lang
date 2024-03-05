package main

import (
	"encoding/json"
	"fmt"
	"net/http"
)

type Student struct {
	Name  string
	Age   int
	Score int
}

func StudentHandler(w http.ResponseWriter, r *http.Request) {
	var studnet = Student{"aaa", 12, 4}
	data, _ := json.Marshal(studnet) // object -> byte
	w.Header().Add("content-type", "application/json")
	w.WriteHeader(http.StatusOK)
	fmt.Fprint(w, string(data))
}

func MakeWebHandler() http.Handler {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprint(w, "Hello World")
	})
	mux.HandleFunc("/bar", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Hello Bar")
	})
	mux.HandleFunc("/student", StudentHandler)
	return mux
}

func main() {
	http.ListenAndServe(":3000", MakeWebHandler())
}

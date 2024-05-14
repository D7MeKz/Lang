package main

import (
	"fmt"
	"math/rand"
	"runtime"
)

func printHeapMemory() {
	var memStats runtime.MemStats
	runtime.ReadMemStats(&memStats)
	heapAllocMB := float64(memStats.HeapAlloc) / 1024 / 1024
	fmt.Printf("Heap allocated memory: %.2f MB\n", heapAllocMB)
}

func main() {
	n := 1_000_000
	m := make(map[int]int, n)
	printHeapMemory()

	for i := 0; i < n; i++ {
		m[i] = rand.Int()
	}
	printHeapMemory()

	for i := 0; i < n; i++ {
		delete(m, i)
	}

	runtime.GC()
	printHeapMemory()
	runtime.KeepAlive(m)
}

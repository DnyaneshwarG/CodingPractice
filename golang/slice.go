package main

import (
	"fmt"
)

func main() {
	a := []int { 1, 2, 3, 4, 5}
	fmt.Println(a)

	b := []bool {true, false, false, false, true}
	fmt.Println(b)

	st := []struct {
		i int
		b bool
	} {
		{1, true},
		{2, false},
		{3, true},
		{4, true},
	}
	fmt.Println(st)

	ar := []int {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}

	printSlice(ar)

	ar = ar[:0]
	printSlice(ar)

	ar = ar[:10]
	printSlice(ar)
}


func printSlice(s []int) {
	fmt.Printf("Len = %d, Capacity = %d, Value = %v\n", len(s), cap(s),	s)
}

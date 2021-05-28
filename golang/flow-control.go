package main

import (
	"fmt"
)

var j int

func pow(sum int) int {
	if k := sum + 10; k < 20 {
		return k
	}
	return sum
}

func main() {
	sum := 0

	for i := 0; i < 10; i++ {
		sum += i
	}

	k := 10
	fmt.Println(sum, j, k)


	fmt.Println(pow(5))
	fmt.Println(pow(10))
}

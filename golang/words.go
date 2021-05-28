package main

import (
	"fmt"
	"strings"
)

func main() {
	s := "I am learning Golang"
	fmt.Println(s)
	words := strings.Fields(s)
	fmt.Println(s, words)
}

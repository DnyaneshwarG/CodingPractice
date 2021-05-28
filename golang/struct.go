package main

import (
	"fmt"
)

type Vertex struct {
	X int
	Y int
}

func main() {
	fmt.Println(Vertex{10, 20})
	v := Vertex{1, 2}
	v.X = 100
	v.Y = 200
	fmt.Println(v)
}

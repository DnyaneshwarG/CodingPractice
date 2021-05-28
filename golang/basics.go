package main

import (
	"fmt"
	"time"
	"math/rand"
	"math/cmplx"
)

func add(x int, y int) int {
	return x + y
}

func add2(x, y int) int {
	return x + y
}

func swap(x, y string) (string, string) {
	return y, x
}

func split(sum int) (x, y int) {
	x = sum + 10
	y = sum - 10
	return
}

var c, python, golang, java bool

var(
  ToBe bool = false
	MaxInt uint64 = 1<<64 - 1
	z complex128 = cmplx.Sqrt(-5 + 12i)
)

const (
	Big = 1 << 10
	Small = Big >> 99
)

func needFloat(x float64) float64 {
	return x * 0.1
}
func main() {
	fmt.Println("\nHello World! GoLang here!")

	fmt.Println("\nYour time is : ", time.Now())

	rand.Seed(time.Now().UnixNano())
	fmt.Println("\nRandom : ", rand.Intn(100))

	fmt.Println("\nAddition of 2 + 3 : ", add(2, 3))

	fmt.Println("\nAddition of 10 + 6 : ", add2(10, 6))

	str0, str1 := swap("Hello", "World!")
	fmt.Println(str0, str1)

	fmt.Println(split(20))

	var i, j int = 1, 2
	fmt.Println(i, j, c, java, golang, python)
	aa, bb, cc := true, false, "no"
	fmt.Println(aa, bb, cc)

	fmt.Printf("\n\nType : %T, Value : %v", ToBe, ToBe)
	fmt.Printf("\nType : %T, Value : %v", MaxInt, MaxInt)
	fmt.Printf("\nType : %T, Value : %v", z, z)
	
	var ii int
	var ff float64
	var jj bool
	var bbb bool
	var str string
	fmt.Printf("%v, %v, %v, %v, %v", ii, ff, bbb, jj, str)

	var iii int = 43
	var jjj float64 = float64(iii)
	var ubb uint = uint(iii)

	iiii := 43
	jjjj := float64(iiii)
	ubbb := uint(iiii)

	fmt.Println(iii, iiii, jjj, jjjj, ubb, ubbb)

	tt := false
	fmt.Printf("\nType of tt is : %T\n", tt)
	
	fmt.Println(needFloat(Big))
	fmt.Printf("\nType of Big is : %T", Big)	



	fmt.Println()
}

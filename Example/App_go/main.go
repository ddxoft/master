package main

import (
	"fmt"
	"unsafe"

	"golang.org/x/sys/windows"
)

var (
	dd  = windows.NewLazyDLL("./dd.dll")
	btn = dd.NewProc("DD_btn")
	key = dd.NewProc("DD_key")
	str = dd.NewProc("DD_str")
)

func main() {
	fmt.Println("Load DD!")

	rt, _, _ := btn.Call(0)
	if rt == 1 {
		fmt.Println("ok")
	} else {
		fmt.Println("load failed")
	}

	key.Call(601, 1) // 1==down, 601=Left.Win (dd key code)
	key.Call(601, 2) // 2=up

	ptr, err := windows.BytePtrFromString("123@aBc")
	if err != nil {
		panic(err)
	}
	rt, _, _ = str.Call(uintptr(unsafe.Pointer(ptr)))
	if rt != 1 {
		panic("input failed")
	}
}

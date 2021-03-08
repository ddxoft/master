package main

import (
	"syscall"
	"time"
)

var ld *syscall.LazyDLL

func main() {
	ld = syscall.NewLazyDLL("DD64.dll")
	keyMap := map[string]uintptr{
		"5": 205, "c": 503, "n": 506, "z": 501, "3": 203, "1": 201, "d": 403, "0": 210, "l": 409, "8": 208, "w": 302,
		"u": 307, "4": 204, "e": 303, "[": 311, "f": 404, "y": 306, "x": 502, "g": 405, "v": 504, "r": 304, "i": 308,
		"a": 401, "m": 507, "h": 406, ".": 509, ",": 508, "]": 312, "/": 510, "6": 206, "2": 202, "b": 505, "k": 408,
		"7": 207, "q": 301, "\"": 411, "\\": 313, "j": 407, "`": 200, "9": 209, "p": 310, "o": 309, "t": 305, "-": 211,
		"=": 212, "s": 402, ";": 410,
	}
	downUp(keyMap, "d")
	downUp(keyMap, "e")
	downUp(keyMap, "m")
	downUp(keyMap, "o")

}

func downUp(keyMap map[string]uintptr, key string) {

	action := ld.NewProc("DD_key")
	vkCode := keyMap[key]
	action.Call(vkCode, 1)
	time.Sleep(time.Millisecond * 200)
	action.Call(vkCode, 2)
}

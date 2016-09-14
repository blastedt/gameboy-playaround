import := ../Generics/

VPATH = ../Generics/

hello.gb: hello.obj Hardware.obj util.obj
	rgblink -m hello.map -n hello.sym -o hello.gb hello.obj util.obj Hardware.obj
	rgbfix -p 0 -v hello.gb

hello.obj: bank0.z80
	rgbasm -o hello.obj bank0.z80

vpath Hardware.obj	../Generics
Hardware.obj: Hardware.inc
	rgbasm -o $@ $^

vpath util.obj ../Generics
util.obj: util.inc
	rgbasm -o $@ $^





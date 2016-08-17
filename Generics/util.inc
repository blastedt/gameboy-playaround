INCLUDE "../Generics/Hardware.inc"

SECTION "util", HOME
WAIT_VBLANK::
	ldh		A,		[_rLY]				;load vertical line
	cp		$91
	jr		nz,		WAIT_VBLANK			;jump short to loop if not in vblank
	ret
;MEMSET
;Loads the memory at HL with size BC with the value at D 
;Changes HL and BC
MEMSET::
	ld 	[HL],	D
	inc		HL
	dec		BC
	ld		A,		B
	or		C							;B OR C -> BC is not zero
	jr		nz,		MEMSET
	ret
;MEMCPY
;Loads the memory at HL with size BC with the memory at DE
MEMCPY::
	ld		A,		[DE]				;load A with the memory at DE
	ld		[HL],	A					;load that into HL
	inc		HL							;move the pointers along
	inc		DE
	dec		BC							;decrement size
	ld		A,		B					;check if B and C are both zero
	or		C
	jr		nz,		MEMCPY				;loop
	ret
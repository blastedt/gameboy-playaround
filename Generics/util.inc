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
	
;GET_INPUT
;Loads A with the current input, accounting for bounce.
;For all of $FF00, 0 means on and 1 means off.
;Bit order
;7 Down		3 Start
;6 Up		2 Select
;5 Left		1 B
;4 Right	0 A
GET_INPUT::
	push BC

	ld 		($FF00),	%00100000			; load P14 by setting it low
	ld		A,			($FF00)
	ld		A,			($FF00)
	ld		A,			($FF00)				; getting arrow keys
	ld		A,			($FF00)				; bounce
	and		%00001111						; get only the output
	swap	A								; move nibblets to other side
	ld		B,			A					; store information
	
	ld		($FF00),	%00010000			; Load P15
	ld		A,			($FF00)
	ld		A,			($FF00)
	ld		A,			($FF00)
	ld		A,			($FF00)
	and		%00001111						; bounce and output mask
	or		B								; add arrow keys
	
	cpl										; complement/inverse, because 0 is pressed

	pop BC
	ret

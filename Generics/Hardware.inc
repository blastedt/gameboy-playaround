;Various equates for use in gameboy assembly
;Author: Tim Rollet
;
;Produced with documentation and aid of similar files.
;Work in progress, will add things as I start using them.

;;;;;;;;;;;;;;RAM

_VRAM         		EQU  			$8000 ; $8000->$A000

_BG_MAP_0			EQU				$9800

_TILE_DATA_0		EQU				$8000 ; $8000->$8FFF
_TILE_DATA_1		EQU				$8800 ; $Should be mostly unused? This is the signed bank, ptr is to -128

;;;;;;;;;;;;;;Video

_BG_PALETTE			EQU				$FF47
_BG_PALETTEH		EQU				$47

;;;;;;;;;;;;;;I/O

_JOYPAD				EQU				$FF00						;Joypad byte

_DPAD_OUT			EQU				%00100000					;Select Dpad by setting this low in _Joypad
_BUTTONS_OUT		EQU				%00010000					;Ditto for buttons

_P10_In				EQU				%00001000					;Button masks
_P11_In				EQU				%00000100
_P12_In				EQU				%00000010
_P13_In				EQU				%00000001


_SB					EQU				$FF01						;Serial transfer data (1 byte at a time)
_SC					EQU				$FF02						;Serial/SIO control
_SC_TSF				EQU				%10000000					;Bit 7 - Transfer start flag; send and receive simultaneous
_SC_CLOCK			EQU				%00000001					;Set to 0 for external clock, 1 for internal

;;;;;;;;;;;;;;Video

_PALETTE_NORMAL		EQU				%11100100					;11 10 01 00 dark to light
_SCY				EQU				$FF42						;scroll y
_SCX				EQU				$FF43						;scroll x

;;;;;;;;;;;;;;Clock
_DIV				EQU				$FF04						;Divider register
_TIMER				EQU				$FF05						;Increments based on clock frequency, interrupts on overflow
_TMA				EQU				$FF06						;loaded when timer overflows (??)

;;;;;;;;;;;;;;Interrupts
_IF					EQU				$FF0F						;Interrupt flag
_IF_BUTTON			EQU				%00010000					;P10-P13 high to low
_IF_SERIAL			EQU				%00001000					;Serial transfer complete
_IF_TIMER			EQU				%00000100					;Timer overflow
_IF_LCDC			EQU				%00000010					;Line interrupt
_IF_VBLANK			EQU				%00000001					;V-blank interrupt

;;;;;;;;;;;;;Sound
_SOUND_OFF			EQU				$FF26
_SOUND_OFF_FLAG		EQU				%10000000					;bit to drop to 0 to disable sound


;;;;;;;;;;;;;LCD control
_LCDC				EQU				$FF40							;begins at 1001 0001
_LCDCH				EQU				$40
_LCDC_OP			EQU				%10000000					;turn LCD on/off, starts on
_LCDC_WND_MAP		EQU				%01000000					;choose $9800 for the window map
_LCDC_WND_DISP		EQU				%00100000					;turn window on or off
_LCDC_BG_TILE		EQU				%00010000					;select which tile bank to use for bg and window
_LCDC_BG_MAP		EQU				%00001000					;select the bg map
_LCDC_OBJ_SIZE		EQU				%00000100					;choose 8x8 or 8x16 sprites (8x8 default, 0)
_LCDC_OBJ_DISP		EQU				%00000010					;enable or disable sprite rendering (default disabled, 0)
_LCDC_BG_DISP		EQU				%00000001					;display the background

_rLY				EQU				$FF44							;$FF44 is lcdc y coordinate, $91 thru $98 mean vblank
_rLYH				EQU				$44

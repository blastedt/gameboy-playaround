# gameboy-playaround
I'm interested in the gameboy's z80 assembly.  I'll be writing all tools used from scratch with the exception of the RGBDS assembler.

Cool stuff I've encountered so far:

* Someone managed to "dump" the Gameboy's boot ROM by looking at it with a microscope bit by bit (256 total bytes)
* Nintendo QA somehow managed to miss a critical bug with the `halt` instruction - the next byte in text after a halt is duplicated, ruining any code but a `nop`.
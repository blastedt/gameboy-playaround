# Image to Tile

Take an 8x8 monochrome png and convert it to z80 assembly (db $val,$val,$val and so on) for copy-pasting into your bank file.  Skip the graph paper!

Requires an install of "ImageMagick" macrod to `magick`.  Unix users may find their install instead automatically macros to `convert` which necessitates a change on either side.

Usage:
* put images in `.` or `img/`
* use `make` to create a tiles.asm from all images
* use `make loud` to keep temporary files and print the assembly to console

Right now this only supports monochrome and assumes that `0x00` is black and `0xFF` is white.  Support for all four colors is coming later.
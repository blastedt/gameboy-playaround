images := $(wildcard *.png) $(wildcard img/*.png)
grays := $(images:.png=.gray)
nul := > NUL

VPATH = img

.PHONY: tiles_and_clean
tiles_and_clean: tiles.asm clean

.PHONY: loud
loud: nul =
loud: tiles.asm

%.gray: %.png
	magick -depth 2 $^ $@

.PHONY: tiles.asm
tiles.asm: $(grays)
	python tilegen.py $(grays) $(nul)

.PHONY: clean
clean: 
	del *.gray
	del img\*.gray


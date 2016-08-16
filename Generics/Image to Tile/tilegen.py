from __future__ import print_function
import sys
def make_byte_list(s):
	res = []
	while (len(s) >= 8):
		res.append( int(s[0:8], 2) )
		s = s[8:]
	return res


#outputs DB command to make tiles from binary string
#all tiles have full brightness (second byte echoes)
#set second byte to $00 for half-bright
def tilegen(s):
	byts = make_byte_list(s)
	print("DB ", end="")
	count = 0
	for byt in byts:
		print("$%X,$%X" % (byt,byt), end="")
		count += 2
		if (count < 8):
			print(",", end="")
		else:
			print("\nDB ", end="")
		count = count % 8

def tilegen_to_string(s, argv):
	res = ""
	byts = make_byte_list(s)
	res += "DB "
	count = 0
	for byt in byts:
		res += "$%X,$%X" % (byt,byt)
		count += 2
		if (count % 8 != 0):
			res += ","
		elif count % 16 == 8:
			res += "\nDB "
		else:
			res += "\t;" + argv[count/16 - 1] + "\nDB "
	res = res[:-4]
	return res


def img_to_tile(img):
	f = open(img, 'r')
	s = f.read()
	binary = ""
	for c in s:
		if ord(c) == 0xFF:
			binary += "0"
		else:
			binary += "1"
	tilegen(binary)

def img_to_binary(img):
	f = open(img, 'r')
	s = f.read()
	binary = ""
	for c in s:
		if ord(c) == 0xFF:
			binary += "0"
		else:
			binary += "1"
	return binary

def main(argv):
	binary = ""
	for img in argv:
		binary += img_to_binary(img)
	s = tilegen_to_string(binary, argv)
	print("\n"+s)
	f = open("tiles.asm", "w")
	f.write(s)
	f.close()

main(sys.argv[1:])
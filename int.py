from random import randint
from sys import argv
if __name__ == "__main__":
	elem = []
	for i in range(int(argv[1])):
		buffer = randint(int(argv[2]), int(argv[3]))
		while buffer in elem:
			buffer = randint(int(argv[2]), int(argv[3]))
		elem.append(buffer)
	s = '"'
	for i in elem:
		s += str(i) + ' '
	s += '"'
	print(s)

	
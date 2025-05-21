all: bfc bfe

bfc: bfc.c
	gcc -o bfc bfc.c

bfe: bfe.c
	gcc -o bfe bfe.c

clean:
	rm -f bfc bfe

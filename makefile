tr.o: translator.h trans.c
	gcc -c trans.c -o tr.o
r: tr.o own.c
	gcc own.c tr.o -o r
run: r
	./r
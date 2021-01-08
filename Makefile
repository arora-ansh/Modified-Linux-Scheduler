compile:
	gcc -lgomp test.c

run: compile
	./a.out

compile2:
	gcc -lgomp test2.c

run2: compile2
	./a.out

clear:
	rm a.out


all: ex07

ex07: lista.o cadastro.o main.o
	gcc -o ex07 lista.o cadastro.o main.o

main.o: aluno.h lista.h cadastro.h
	gcc -o main.o main.c -c

fila.o: fila.h fila.cadastro
	gcc -o fila.o fila.c -c

cadastro.o: aluno.h lista.h cadastro.h 
	gcc -o cadastro.o cadastro.c -c

clean:
	rm -f *.o ex07
all: saida.exe

saida.exe: fila00.o usafila00.o
		gcc -Wall -o saida.exe fila00.o usafila00.o

fila00.o: fila00.c
		gcc -Wall -c fila00.c

usafila00.o: usafila00.c
		gcc -Wall -c usafila00.c

clean:
		rm *.o *.exe a.out

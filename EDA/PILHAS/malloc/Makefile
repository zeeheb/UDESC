all: saida.exe

saida.exe: func.o ap1.o
		gcc -Wall -o saida.exe func.o ap1.o

func.o: func.c
		gcc -Wall -c func.c

ap1.o: ap1.c
		gcc -Wall -c ap1.c

clean:
		rm func.o ap1.o saida.exe

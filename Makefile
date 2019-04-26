binary: mySimpleComputer.o main.o
	gcc -o binary mySimpleComputer.o main.o -L. 
main.o: main.c
	gcc -c main.c
mySimpleComputer.o: mySimpleComputer.c
	gcc -c mySimpleComputer.c
clean:
	rm -f *.o binary

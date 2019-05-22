binary: mySimpleComputer.o myTerm.o main.o
	gcc -o binary mySimpleComputer.o myTerm.o main.o -L. 
main.o: main.c
	gcc -c main.c
mySimpleComputer.o: mySimpleComputer.c
	gcc -c mySimpleComputer.c
myTerm.o: myTerm.c
	gcc -c myTerm.c
clean:
	rm -f *.o binary

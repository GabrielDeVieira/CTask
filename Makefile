run: all
	./programa

all:
	gcc -c -Wall *.c; 
	gcc -o programa *.o;
	rm *.o

clean:
	rm programa
	rm *.dat

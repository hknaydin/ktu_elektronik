CC                 = gcc
CFLAGS             = -pthread
OBJ                = test.o

test: test.o
	$(CC) -o test main.c

test.o: main.c
	$(CC) -c main.c





clean:
	rm -f *.o $(TARGET) $(OBJ)

install: test
	cp test /home/mavialp/Desktop/cdersleri/ders1/derleme




.PHONY: test

GFLAGS=-I ../src -Wall -grep


test: test-linked-list
	./test-linked-list
	valgrind ./test-linked-list

test-linked-list: test-linked-list.o ../linked-list/linked-list.o

../linked-list/linked-list.o:
	${MAKE} -C ../linked-list linked-list.o

clean:
	rm -f test-linked-list *.o

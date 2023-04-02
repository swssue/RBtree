.PHONY: test

CFLAGS=-I ../src -Wall -g #-DSENTINEL
# valgrind : 실행 중인 실행파일을 모니터링 누수, 관리 담당
test: test-rbtree
	./test-rbtree
	valgrind ./test-rbtree 

test-rbtree: test-rbtree.o ../src/rbtree.o

../src/rbtree.o:
	$(MAKE) -C ../src rbtree.o

clean:
	rm -f test-rbtree *.o 

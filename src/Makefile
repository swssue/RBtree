# clean 파일이 실제로 존재하지 않아도, make clean 명령어를 실행 가능
.PHONY: clean

CFLAGS=-Wall -g
# driver.o와 rbtree.o를 링크하여 driver라는 실행파일 만들어냄 => 메인에서는 해당 명령어를 build로 실행시킴
driver: driver.o rbtree.o

clean:
	rm -f driver *.o

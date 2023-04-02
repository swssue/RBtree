.PHONY: test
 # 타겟으로 작성한 이름과, 디렉토리 내에 이름이 서로 같을 경우, 오작동을 일으키지 않기 위해 .PHONY 사용

# 디버깅 용도(큰 프로젝트에서 디버깅을 하려면 어디에서 오류가 났는지 찾기 어렵기 때문에 아래 명령어로 수행)
CFLAGS=-I ../src -Wall -g #-DSENTINEL
# -I : include 디렉토리 지정 , 상위 디렉토리의 src 디렉토리를 포함시킴(test 폴더에서 src 폴더 내에 있는 파일들이 수행되는데 src 파일들도 디버깅 정보를 보기 위해서 ../src 하는 듯)
# -Wall : 모든 경고를 표시
# -g : 디버깅 정보를 포함
# -DSENTINEL : SENTINEL이라는 매크로 상수를 정의

test: test-rbtree
	./test-rbtree
# test-rbtree 실행
	valgrind ./test-rbtree 
# valgrind : 실행 중인 실행파일을 모니터링 누수, 관리 담당

test-rbtree: test-rbtree.o ../src/rbtree.o
# test-rbtree는 test-rbtree.0와 ../src/rbtree.o를 링크하여 실행파일 만듬 

../src/rbtree.o: # 위의 두개와 달리 명령어 타겟이 아니라, 명령어 실행시 의존성 파일을 생성하는 룰
	$(MAKE) -C ../src rbtree.o
# ../src폴더에서 Makefile찾아서 rbtree.o를 빌드함
clean:
	rm -f test-rbtree *.o 
# make file에서 생성된 파일들을 삭제
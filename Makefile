.PHONY: help build test # 실제 명령어가 존재하지 않아도 실행 가능
# 명령어를 프롬포트에 알 수 있게 띄어주는 미리 선언된 명령어
help:
# http://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
	@grep -E '^[a-zA-Z0-9_%/-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

# $(MAKE) : 해당 위치에 있는 Makefile 실행, -C : 디렉터리 위치, src : Makefile이 위치한 디렉터리, clean/test : 해당 디렉터리 내 Makefile의 명령어 실행   
build:
build: ## Build executables
	$(MAKE) -C src 


test:
test: ## Test rbtree implementation
	$(MAKE) -C test test
	
clean:
clean: ## Clear build environment
	$(MAKE) -C src clean
	$(MAKE) -C test clean

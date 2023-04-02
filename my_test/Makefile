.PHONY: help build test

help:
# http://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
	@grep -E '^[a-zA-Z0-9_%/-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

build: ## build run
	${MAKE} -C linked-list
test: ## test run
	${MAKE} -C test test
clean: ## clean run
	${MAKE} -C linked-list clean
	${MAKE} -C test clean

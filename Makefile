EXAMPLE_DIRECTORY:="examples"
EXPRESSION:="1+5-6+1"

.PHONY: all
all: examples

.PHONY: examples
examples:
	@echo "Testing against expression: $(EXPRESSION)"
	@find $(EXAMPLE_DIRECTORY) -type f | while read line; do \
		echo "\nCompiling $$line ..."; \
		clang $$line; \
		echo $(EXPRESSION) | ./a.out; \
	done
	@echo "\nCleaning up ./a.out"
	@rm a.out

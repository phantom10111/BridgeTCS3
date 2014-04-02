override ROOT := .
include $(ROOT)/*.mk

all: tests

clean:
	cd src && $(MAKE) clean
	cd test && $(MAKE) clean
	$(RM) tests

test: tests

tests:
	cd test && $(MAKE) tests
	cp test/tests .

.PHONY: all clean test

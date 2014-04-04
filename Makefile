override ROOT := .
include $(ROOT)/*.mk

all: test

clean:
	cd src && $(MAKE) clean
	cd test && $(MAKE) clean

test: tests
	test/tests

tests:
	cd test && $(MAKE) tests

%Test:
	cd test && $(MAKE) $*Test

.PHONY: all clean test tests

override ROOT := .
include $(ROOT)/*.mk

all: bridge test

bridge:
	cd src && $(MAKE) bridge

clean:
	cd src && $(MAKE) clean
	cd test && $(MAKE) clean

test: tests
	test/tests

tests:
	cd test && $(MAKE) tests

%Test:
	cd test && $(MAKE) $*Test

.PHONY: all bridge clean test tests

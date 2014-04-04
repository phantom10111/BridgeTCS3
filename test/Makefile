override ROOT = ..
include $(ROOT)/*.mk

override LINK_FLAGS += -lgmock -lgtest -lgtest_main -pthread

all: test

clean:
	$(CLEAN) tests *Test

test: tests
	./tests

$(ROOT)/src/test.a:
	cd $(ROOT)/src && $(MAKE) test.a

tests: $(OBJECT_FILES) $(ROOT)/src/test.a
	$(LINK)

%Test: %Test.o $(ROOT)/src/test.a
	$(LINK)
	./$*Test

.PHONY: all clean test

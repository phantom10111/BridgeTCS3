override ROOT = ..
include $(ROOT)/*.mk

override LINK_FLAGS += -lgmock -lgmock_main -pthread
override OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *Test.cpp))

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

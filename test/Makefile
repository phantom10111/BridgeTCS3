override ROOT = ..
include $(ROOT)/*.mk

override LINK_FLAGS += -lgmock_main -lgmock -lgtest -pthread
override OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *Test.cpp))

all: test

clean:
	$(CLEAN) tests *Test

test: tests
	./tests

$(ROOT)/src/model/model.a:
	cd $(ROOT)/src/model && $(MAKE) model.a

tests: $(OBJECT_FILES) $(ROOT)/src/model/model.a
	$(LINK)

%Test: %Test.o $(ROOT)/src/model/model.a
	$(LINK)
	./$*Test

.PHONY: all clean test $(ROOT)/src/model/model.a

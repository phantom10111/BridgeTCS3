override ROOT := ..
include $(ROOT)/*.mk

override OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: bridge

bridge: $(OBJECT_FILES)
	$(LINK)

clean:
	$(CLEAN) bridge test.a

test.a: $(OBJECT_FILES)

.PHONY: all clean

override ROOT := ../../..
include $(ROOT)/*.mk

override OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: ui.text.a

clean:
	$(CLEAN) ui.text.a

ui.text.a: $(OBJECT_FILES)

.PHONY: all clean

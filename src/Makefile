override ROOT := ..
include $(ROOT)/*.mk

override OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: bridge

bridge: $(OBJECT_FILES) ui/text/ui.text.a
	$(LINK)

clean:
	$(CLEAN) bridge test.a

test.a: $(OBJECT_FILES)

ui/text/ui.text.a:
	cd ui && $(MAKE) text/ui.text.a

.PHONY: all clean ui/text/ui.text.a

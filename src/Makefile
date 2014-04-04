override ROOT := ..
include $(ROOT)/*.mk

all: bridge

bridge: $(OBJECT_FILES)
	$(LINK)

clean:
	$(CLEAN) bridge test.a

test.a: $(OBJECT_FILES)

.PHONY: all clean

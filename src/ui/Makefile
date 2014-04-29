override ROOT := ../..
include $(ROOT)/*.mk

all: text/ui.text.a

clean:
	cd text && $(MAKE) clean

text/ui.text.a:
	cd text && $(MAKE) ui.text.a

.PHONY: all clean text/ui.text.a

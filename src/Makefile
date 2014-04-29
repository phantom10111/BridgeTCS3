override ROOT := ..
include $(ROOT)/*.mk

override OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: bridge

bridge: $(OBJECT_FILES) model/model.a ui/text/ui.text.a
	$(LINK)

clean:
	cd model && $(MAKE) clean
	cd ui && $(MAKE) clean
	$(CLEAN) bridge

model/model.a:
	cd model && $(MAKE) model.a

ui/text/ui.text.a:
	cd ui && $(MAKE) text/ui.text.a

.PHONY: all clean model/model.a ui/text/ui.text.a

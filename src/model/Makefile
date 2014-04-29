override ROOT := ../..
include $(ROOT)/*.mk

override OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: model.a

clean:
	$(CLEAN) model.a

model.a: $(OBJECT_FILES)

.PHONY: all clean

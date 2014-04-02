override ROOT := ..
include $(ROOT)/*.mk

override OBJECT_FILES := \
	Arbiter.o \
	Bidding.o \
	BridgeDeck.o \
	Call.o \
	Card.o \
	Contract.o \
	Hand.o \
	Play.o \
	Trick.o

all: test.a

clean:
	$(CLEAN)

test.a: $(OBJECT_FILES)

.PHONY: all clean

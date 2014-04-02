override ROOT = ..
include $(ROOT)/*.mk

override OBJECT_FILES := \
	ArbiterTest.o \
	BiddingTest.o \
	CardTest.o \
	DeckTest.o \
	DenominationTest.o \
	HandTest.o \
	LevelTest.o \
	PlayTest.o \
	TrickTest.o

override LINK_FLAGS += -lgmock -lgtest -lgtest_main -pthread

all: tests

clean:
	$(CLEAN) tests

test: tests

../src/test.a:
	cd ../src && $(MAKE) test.a

tests: $(OBJECT_FILES) ../src/test.a
	$(LINK)

.PHONY: all clean tests

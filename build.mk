override CLEAN = $(RM) *.o .*.d
override COMPILE_FLAGS = -std=c++11 -MMD -MP -I$(ROOT)/src
override LINK = $(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) $(LINK_FLAGS) $(OUTPUT_OPTION)
override LINK_FLAGS :=
override OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

CXXFLAGS := -O2

%.a:
	ar rcs $@ $^

%.d:;

%.o: %.cpp
	$(COMPILE.cpp) $(COMPILE_FLAGS) $(OUTPUT_OPTION) $<
	mv $*.d .$*.d

-include *.d

.DEFAULT_GOAL := all

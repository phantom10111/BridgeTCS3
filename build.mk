override CLEAN = $(RM) *.o .*.d
override COMPILE_FLAGS = -std=c++11 -MMD -MP -I$(ROOT)/src $(EXTRA_FLAGS)
override LINK = $(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) $(LINK_FLAGS) $(OUTPUT_OPTION)
override LINK_FLAGS :=

CXXFLAGS := -g

%.a:
	$(AR) $(ARFLAGS) $@ $^

%.d:;

%.o: %.cpp
	$(COMPILE.cpp) $(COMPILE_FLAGS) $(OUTPUT_OPTION) $<
	mv $*.d .$*.d

-include .*.d

.DEFAULT_GOAL := all

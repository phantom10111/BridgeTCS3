override CLEAN = $(RM) *.o *.d
override COMPILE_FLAGS := -std=c++11 -MMD -MP -I$(ROOT)/src
override LINK_FLAGS :=

CXXFLAGS := -O2

%.a:
	ar rcs $@ $^

%.d:;

%.o: %.cpp
	$(COMPILE.cpp) $(COMPILE_FLAGS) $(OUTPUT_OPTION) $<
	mv $@.d .$@.d

%:
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) $(LINK_FLAGS) $(OUTPUT_OPTION)

-include *.d

.DEFAULT_GOAL := all

.PHONY: %.d

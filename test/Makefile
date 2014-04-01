CPP := $(wildcard *.cpp)
EXE := $(patsubst %.cpp,%,${CPP})

all : ${EXE}

${EXE} : % : %.cpp
	g++ -std=c++11 -pthread $< ../src/*.cpp -I../src -lgmock -lgtest -lgtest_main -o $@

clean :
	rm -f ${EXE}

.PHONY : all clean

CC=g++
CFLAGS= -Wall -Wextra -pedantic -O3 -ansi
SOURCES=main.cpp root.cpp
OBJECTS=$(SOURCES:.cpp=.o)
.PRECIOUS: test.o $(SOURCES:.cpp=_test.o)
EXECUTABLE=main

all: $(EXECUTABLE)

-include $(SOURCES:.cpp=.d) $(SOURCES:.cpp=_test.d) test.d

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ -lgsl -lgslcblas

%_test: %_test.o %.o test.o
	$(CC) $(CFLAGS) $*_test.o $*.o test.o -o $@ -lgsl -lgslcblas

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) -MM $< > $*.d

clean:
	rm -f *.o *.d $(EXECUTABLE) *_test *.pyc

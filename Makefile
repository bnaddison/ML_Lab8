# ADDBRA001 Makefile Template

## FLAGS ==================================================================
CC=g++ -std=c++11
LIBS=-lm
## ========================================================================

value: value.o
	$(CC) value.o -o value $(LIBS)


value.o: value.cpp
	$(CC) -c value.cpp

clean:
	@rm -f *.o
	@rm value

install:

	@mv value ~/bin

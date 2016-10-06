# Variables
MESA = /usr/bin/Mesa-5.0
INCPATH = -I$(MESA)/include
LIBPATH = -L$(MESA)/lib
LIBS = -lglut -lGLU -lGL -lm
CFLAGS = $(INCPATH) -g
LFLAGS = $(LIBPATH) $(LIBS)

# Main targets
A: A.o
	gcc -o A A.o $(LFLAGS)

# Source targets
A.o: A.c
	gcc -c A.c $(CFLAGS)

# Clean up
clean:
	rm -f *.o *~

realclean: clean
	rm -f A
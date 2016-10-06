# Variables
MESA = /usr/bin/Mesa-5.0
INCPATH = -I$(MESA)/include
LIBPATH = -L$(MESA)/lib
LIBS = -lglut -lGLU -lGL -lm
CFLAGS = $(INCPATH) -g
LFLAGS = $(LIBPATH) $(LIBS)

# Main targets
prim: prim.o
	gcc -o prim prim.o $(LFLAGS)

# Source targets
prim.o: prim.c
	gcc -c prim.c $(CFLAGS)

# Clean up
clean:
	rm -f *.o *~

realclean: clean
	rm -f prim
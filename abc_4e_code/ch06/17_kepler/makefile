CC      =  cc
CFLAGS  =
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  bisection.o  kepler.o

$(EXEC): $(OBJS)
        @echo "linking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS) -lm

$(OBJS): kepler.h
        $(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
        @echo "relinking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

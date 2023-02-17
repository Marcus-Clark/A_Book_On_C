CC      =  gcc
CFLAGS  =  -Wall -g
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  chk.o  fill.o  space.o  trace.o  wrt.o

$(EXEC): $(OBJS)
        @echo "linking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): trace.h
        $(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
        @echo "relinking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

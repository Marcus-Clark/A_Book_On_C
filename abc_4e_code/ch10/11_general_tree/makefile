CC      =  gcc
CFLAGS  =  -Wall -g
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  build.o  gtree.o  traversal.o  wrt.o

$(EXEC): $(OBJS)
        @echo "linking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): gtree.h
        $(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
        @echo "relinking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

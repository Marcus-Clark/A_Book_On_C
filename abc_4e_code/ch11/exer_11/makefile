CC      =  gcc
CFLAGS  =  -Wall
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  careful.o  get.o  graceful.o  wrt_rand.o

$(EXEC): $(OBJS)
        @echo "linking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): wrt_rand.h
        $(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
        @echo "relinking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

CC      =  cc
CFLAGS  =
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  compare.o

$(EXEC): $(OBJS)
        @echo "linking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): sort.h
        $(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
        @echo "relinking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

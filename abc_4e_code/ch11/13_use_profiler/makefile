CC      =  cc
CFLAGS  =  -v -p
EXEC    =  quicksort
INCLS   =  
LIBS    =  

OBJS    =  main.o  find_pivot.o  partition.o  quicksort.o

$(EXEC): $(OBJS)
        @echo "linking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): quicksort.h
        $(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
        @echo "relinking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

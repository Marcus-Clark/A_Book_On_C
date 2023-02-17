CC      =  cc
CFLAGS  =  -v
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  error.o  get.o  oper.o  skip.o  wrt.o

$(EXEC): $(OBJS)
        @echo "linking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): complex.h
        $(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
        @echo "relinking ..."
        @$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

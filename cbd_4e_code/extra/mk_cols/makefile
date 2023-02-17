CC      =  g++
CFLAGS  =  -Wall
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  compare.o  error.o  fct.o  matrix.o  mk_cols.o  \
           oper.o  options.o  wrt.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): mk_cols.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

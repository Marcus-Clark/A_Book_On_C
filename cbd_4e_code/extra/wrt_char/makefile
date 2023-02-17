CC      =  g++
CFLAGS  =  -Wall
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o     action.o  error.o  fct.o  grace.o  oper.o  \
           options.o  wrt.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): wrt_char.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

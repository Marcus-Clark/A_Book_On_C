BASE    =  /home/blufox/base
CC      =  g++
CFLAGS  =  -Wall
EXEC   =  a.out
INCLS   =
LIBS    =
LOCAL   =

OBJS  =  main.o  bit_print.o  print.o  run_run.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): try_me.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

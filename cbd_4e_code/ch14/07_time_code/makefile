BASE    =  /home/blufox/base
CC      =  gcc
CFLAGS  =  -Wall
EXEC   =  a.out
INCLS   =
LIBS    =
LOCAL   =

OBJS  =  main.o  time_keeper.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): time_mult.h u_lib.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

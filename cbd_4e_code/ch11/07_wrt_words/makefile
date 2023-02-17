BASE    =  /home/blufox/base
CC      =  g++
CFLAGS  =  -Wall
EXEC   =  a.out
INCLS   =
LIBS    =
LOCAL   =

OBJS  =  main.o  print.o  wrt_bkwds.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): wrt_bkwds.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

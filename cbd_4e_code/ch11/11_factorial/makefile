BASE    =  /home/blufox/base
CC      =  g++
CFLAGS  =  -Wall
EXEC   =  a.out
INCLS   =
LIBS    =
LOCAL   =

OBJS  =  main.o  fact.o  print.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): fact.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

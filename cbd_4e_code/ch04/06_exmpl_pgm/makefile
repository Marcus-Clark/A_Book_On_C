BASE    =  /home/blufox/base
CC      =  gcc
CFLAGS  =  -Wall
EXEC   =  pgm
INCLS   =
LIBS    =
LOCAL   =

OBJS  =  main.o  fct.o  print.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): pgm.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

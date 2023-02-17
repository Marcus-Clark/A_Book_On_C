BASE    =  /home/blufox/base
CC      =  gcc
CFLAGS  =  -Wall
EXEC   =  a.out
INCLS   =
LIBS    =
LOCAL   =

OBJS  =  main.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): a_b_c.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

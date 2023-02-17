BASE    =  /home/blufox/base
CC      =  gcc
CFLAGS  =  -Wall
EXEC    =  pgm
INCLS   =
LIBS    =
LOCAL   =

OBJS  =  main.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS):
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

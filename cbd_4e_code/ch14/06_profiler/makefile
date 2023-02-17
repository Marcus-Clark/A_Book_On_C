BASE    =  /home/blufox/base
CC      =  gcc
CFLAGS  =  -Wall -p
EXEC   =  compare_sorts
INCLS   =
LIBS    =
LOCAL   =

OBJS  =  main.o   chk_arrays.o  compare.o  grace.o  \
         print.o  slow_sort.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): cmp_sorts.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

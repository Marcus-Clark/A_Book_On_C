BASE    =  /home/blufox/base
CC      =  gcc
CFLAGS  =
EXEC   =  a.out
INCLS   =
LIBS    =

OBJS  =  main.o  compare.o  print.o  report.o  selection.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): p_r_s.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

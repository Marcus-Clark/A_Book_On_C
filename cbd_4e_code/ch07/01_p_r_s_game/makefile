CC      =  gcc
CFLAGS  =  -Wall
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  compare.o  report.o  selection.o  wrt.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): p_r_s.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

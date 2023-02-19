CC      =  cc
CFLAGS  =
EXEC    = bisect_prg 
INCLS   =  
LIBS    =  

OBJS    =  main.o  bisection.o  fct.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): find_root.h
	@$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)
clean:
	rm *.o
	rm *_prg


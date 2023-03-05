CC      =  cc
CFLAGS  =
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  add.o  wrt.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)

$(OBJS): add.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  i$(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)
clean:
	rm *.o
	rm a.out

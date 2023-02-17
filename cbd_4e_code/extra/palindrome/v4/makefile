CC      =  g++
CFLAGS  =  -Wall
EXEC    =  a.out
INCLS   =  
LIBS    =  

OBJS    =  main.o  palindrome.o

$(EXEC): $(OBJS)
	@echo "linking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)
	chmod a+rx $(EXEC)

$(OBJS):
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(EXEC)  $(OBJS)  $(LIBS)
	chmod a+rx $(EXEC)

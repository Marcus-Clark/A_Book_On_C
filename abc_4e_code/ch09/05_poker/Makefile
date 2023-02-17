CC=cc
CFLAGS=-I. -lm
DEPS = poker.h
OBJ = main.o poker.o swap.o wrt.o

%.o: %.c $(DEPS)
	$(CC) -c  -o $@ $< $(CFLAGS)
poker_prg: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm poker_prg


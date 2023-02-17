CC=cc
CFLAGS=-I. -lm
DEPS = hanoi.h
OBJ = main.o get.o move.o

%.o: %.c $(DEPS)
	$(CC) -c  -o $@ $< $(CFLAGS)
hanoi_prg: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm hanoi_prg


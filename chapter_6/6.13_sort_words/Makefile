CC=cc
CFLAGS=-I.
DEPS = sort.h
OBJ = main.o error.o sort.o swap.o wrt.o

%.o: %.c $(DEPS)
	$(CC) -c  -o $@ $< $(CFLAGS)
sort_words_prg: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm sort_words_prg


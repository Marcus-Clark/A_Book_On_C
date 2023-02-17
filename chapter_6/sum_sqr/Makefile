CC=cc
CFLAGS=-I. -lm
DEPS = sum_sqr.h
OBJ = main.o fct.o sum_sqr.o

%.o: %.c $(DEPS)
	$(CC) -c  -o $@ $< $(CFLAGS)
sum_sqr_prg: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm sum_sqr_prg


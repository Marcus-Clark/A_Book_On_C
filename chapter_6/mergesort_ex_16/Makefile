CC=cc
CFLAGS=-I.
DEPS = mergesort.h
OBJ = main.o merge.o mergesort.o wrt.o

%.o: %.c $(DEPS)
	$(CC) -c  -o $@ $< $(CFLAGS)
mergesort_prg: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm mergesort_prg

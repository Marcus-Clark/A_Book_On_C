CC=cc
CFLAGS=-I. -lm
DEPS = p.r.s.h
OBJ = main.o compare.o report.o selection.o  wrt.o

%.o: %.c $(DEPS)
	$(CC) -c  -o $@ $< $(CFLAGS)
prs_prg: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm prs_prg


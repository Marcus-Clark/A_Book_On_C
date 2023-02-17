## ---
## MAKEXEC for the graceful library.
##

ARCHIVE = g_lib.a                    ## this is the library
BASE    =  /home/blufox/base
CC      = gcc
CFLAGS  = -Wall -O
INCLS   =
HEADER  = g_lib.h

CODE  =  gcalloc.c   gchmod.c   gfclose.c  gfopen.c   gfseek.c   \
         ggetcwd.c   ggetenv.c  gmalloc.c  gpclose.c  gpopen.c   \
         grealloc.c  gremove.c  grename.c  gstat.c    gutimes.c

OBJS  =  gcalloc.o   gchmod.o   gfclose.o  gfopen.o   gfseek.o   \
         ggetcwd.o   ggetenv.o  gmalloc.o  gpclose.o  gpopen.o   \
         grealloc.o  gremove.o  grename.o  gstat.o    gutimes.o

$(ARCHIVE): $(OBJS)
	@echo ---
	/usr/bin/rm -f $(ARCHIVE)
	ar ruv $(ARCHIVE) $(OBJS)     ## create the library
	## ranlib $(ARCHIVE)          ## randomize the library, needed
				      ## on some older UNIX systems
	ar t $(ARCHIVE)
	@echo ---
	ls -l $(ARCHIVE) $(HEADER)
	@echo ---

$(OBJS): $(HEADER)
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

clean:
	rm -f g_lib.a *.o

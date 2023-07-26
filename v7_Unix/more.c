/*********************************************************************
 * UNIX pager (v7 compatible)   Chipmaster and KenUnix
 *
 * cc -o more more.c
 *
 * Usage examples:
 *   man wall | more
 *   more xyz
 *   more abc def xyz
 *
 * Started February 15th, 2023 YeOlPiShack.net
 *
 * This is the ultimately dumbest version of more I have experienced.
 * Its main purpose is to illustrate the use of /dev/tty to interact
 * with the user while in a filter role (stdin -> stdout). This also
 * leaves stderr clear for actual errors.
 *
 *
 * NOTES on Antiquity:
 *
 *   - The early C syntax didn't allow for combining type information
 *     in the parenthesized argument list only the names were listed.
 *     Then a "variable" list followed the () and preceded the { that
 *     declared the types for the argument list.
 *
 *   - There is no "void", specifically there is no distinction
 *     between a function that returns an int or nothing at all.
 *
 *   - Many of the modern day header files aren't there.
 *
 *   - Apparently "/dev/tty" couldn't be opened for both reading and
 *     writing on the same FD... at least not in our VM.
 *
 *   - Apparently \a wasn't defined yet either. So I use the raw code
 *     \007.
 *
 *   - Modern compilers gripe if you do an assignment and comparison in
 *     the same statement without enclosing the assignment in (). The
 *     original compilers did not. So if it looks like there are too
 *     many ()s it's to appease the modern compiler gods.
 *
 *   - I'm not sure where they hid errno if there was one. I'd think
 *     there had to be. Maybe Kernighan or Pike knows...
 *
 *********************************************************************/
#include <stdio.h>

/*** Let's make some assumptions about our terminal columns and lines. ***/

#define T_COLS  80
#define T_LINES 24

/*** Let's set up our global working environment ***/

FILE *cin;              /* TTY (in) */
FILE *cout;             /*  |  (out) */
int   ct = 0;

/*** message to stderr and exit with failure code ***/

err(msg)
  char *msg;
{
  fputs(msg, stderr);
  exit(1);
}

/*** A poor man's CLear Screen ***
 *
 * Yup! This is how they used to do it, so says THE Kenrighan & Pike!
 * termcap?!?! What's that?
 */

cls()
{
  int x;
  for(x=0; x<T_LINES; ++x) fputc('\n', cout);
  ct = 0; /* reset global line count */
}

/*** The PAUSE prompt & wait ***/

pause()
{
  char in[T_COLS+1]; /* TTY input buffer */

  fflush(stdout); /*JIC*/
  fputs("--- [ENTER] to continue --- Ctrl-d exits ", cout);
  fflush(cout);
  if(!fgets(in, 81, cin)) {
    /* ^D / EOF */
    fputc('\n', cout); /* cleaner terminal */
    exit(0);
  }
}

/*** Read and page a "file" ***/

int pg(f)
  FILE *f;
{
  char  buf[T_COLS+1];   /* input line: usual term width + \0 */

  /*** read and page stdin ***/

  while(fgets(buf, sizeof(buf), f)) {
    /* page break at T_LINES */
    if(++ct==T_LINES) {
      pause();
      ct = 1;
    }
    fputs(buf, stdout);
  }
  return 0;
}

/*** Let's do some paging!! ***/

int main(argc, argv)
  int argc;
  char *argv[];
{
  FILE *in;
  int x, er;

  /*** Grab a direct line to the TTY ***/

  if(!(cin=fopen("/dev/tty", "r")) || !(cout=fopen("/dev/tty", "w")))
    err("\007Couldn't get controlling TTY\n");

  /*** with CLI args ***/

  if(argc>1) {
    er = 0;
    for(x=1; x<argc; ++x) {
      if(argc>2) {
        if(!er) cls();
        er = 0;
        /* remember all user interaction is on /dev/tty (cin/cout) */
        fprintf(cout, ">>> %s <<<\n", argv[x]);
        pause();
      }

      /* - is tradition for stdin */
      if(strcmp("-", argv[x])==0) {
        pg(stdin);

      /* it must be a file! */
      } else if((in=fopen(argv[x], "r"))) {
        pg(in);
        fclose(in);
      } else {
        /* errors go on stderr... JIC someone want to log */
        fprintf(stderr, "Could not open '%s'!\n", argv[x]);
        fflush(stderr);
        er = 1; /* this prevents cls() above. */
      }

    }

  /*** no args - read and page stdin ***/
  } else {
    pg(stdin);
  }

  return 0;
}

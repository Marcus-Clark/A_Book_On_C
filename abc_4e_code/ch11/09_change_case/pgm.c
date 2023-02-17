/* Change the case of letters in a file. */

#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>         /* use io.h in MS_DOS */

#define   BUFSIZE   1024

int main(int argc, char **argv)
{
   char   mybuf[BUFSIZE], *p;
   int    in_fd, out_fd, n;

   in_fd = open(argv[1], O_RDONLY);
   out_fd = open(argv[2], O_WRONLY | O_EXCL | O_CREAT, 0600);
   while ((n = read(in_fd, mybuf, BUFSIZE)) > 0) {
      for (p = mybuf; p - mybuf < n; ++p)
       if (islower(*p))
          *p = toupper(*p);
       else if (isupper(*p))
          *p = tolower(*p);
      write(out_fd, mybuf, n);
   }
   close(in_fd);
   close(out_fd);
   return 0;
}

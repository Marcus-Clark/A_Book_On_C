   char   *s;
   int    nfrogs;
   .....                           /* get nfrogs from somewhere */
   s = (nfrogs == 1) ? "" : "s";
   printf("We found %d frog%s in the pond.\n", nfrogs, s);

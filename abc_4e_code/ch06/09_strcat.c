char   *strcat(char *s1, const char *s2)
{
   register char   *p = s1;

   while (*p)
      ++p;
   while (*p++ = *s2++)
      ;
   return s1;
}

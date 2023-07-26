unsigned strlen(const char *s)
{
   register int   n;

   for (n = 0; *s != '\0'; ++s)
      ++n;
   return n;
}

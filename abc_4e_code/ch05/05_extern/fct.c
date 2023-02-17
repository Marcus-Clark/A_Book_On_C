int f(void)
{
   extern int   a;             /* look for it elsewhere */
   int          b, c;

   a = b = c = 4;
   return (a + b + c);
}

#include "str_to_l.h"


/* Count a linked list recursively. */

int count(elem *hp)
{
   if (hp == NULL)                                              /* base case */
      return 0;
   else
      return (1 + count(hp -> next));
}


/* Find vowels in the linked list pointed to by hp. */

void find_vowels(elem *hp)
{
   elem   *hvp;                                        /* head vowel pointer */
   elem   *p;
   elem   *q;

   hvp = string_to_list("aeiou");
   for (p = hvp; p != NULL; p = p -> next) {
      q = lookup(p -> d, hp);
      if (q != NULL)
         printf("   %c%s\n", p -> d, ": found it");
      else
         printf("   %c%s\n", p -> d, ": not in your string");
   }
}


/* Lookup c in the linked list pointed to by hp. */

elem *lookup(data c, elem *hp)
{
   if (hp == NULL)                                              /* base case */
      return NULL;
   else if (hp -> d == c)
      return hp;
   else
      return lookup(c, hp -> next);
}


/* List creation by recursion. */

elem *string_to_list(cchr *s)
{
   elem   *hp;

   if (*s == '\0')                                              /* base case */
      return NULL;
   else {
      hp = malloc(sizeof(elem));
      hp -> d = *s;
      hp -> next = string_to_list(s + 1);                  /* recursive call */
      return hp;
   }
}

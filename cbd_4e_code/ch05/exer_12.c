/*
// Thr r 26 lttrs n th lphbt bt sm f th lttrs d nt gt
// sd vry mch.  W prbbly cld gt by wtht th lttr z, fr xmpl.
// Cn w d wy wth th vwls nd stll mk sns f th prntd pg?
// Th ncnt gyptns wrt n hrglyphcs,  systm n whch vwls r
// nt rprsntd, nd tht systm f wrtng lstd  vry lng tm.  Prhps
// wrttn nglsh cn ls b rd ftr ll th vwls hv bn rmvd.
//
// Th rvrs schm f thrwng t ll th cnsnnts prbbly rslts n
// nrdbl txt mst f tm.
//
// ee ae 26 ee i e aae u oe o e ee o o e
// ue e u.  e oa ou e  iou e ee , o eae.
// a e o aa i e oe a i ae ee o e ie ae?
// e aie Eia oe i ieoi, a e i i oe ae
// o eeee, a a e o ii ae a e o ie.  ea
// ie Ei a ao e ea ae a e oe ae ee eoe.
//
// e eee ee o oi ou a e oaa oa eu i
// ueaae e o o ie.
*/

#include <ctype.h>
#include <stdio.h>

int   isvowel(int c);

int main(void)
{
   int   c;

   while ((c = getchar()) != EOF) {
      if (isalpha(c)) {
         if (isvowel(c))
            putchar(c);
      }
      else
         putchar(c);
   }
   return 0;
}

int isvowel(int c)
{
   if (   c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
       || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
      return 1;
   return 0;
}

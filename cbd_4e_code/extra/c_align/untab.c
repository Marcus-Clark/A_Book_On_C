// ---
// Date: Sat, 2 May 87 11:21:38 PDT
// From: xxcc003@ucsck.ucsc.edu (Harry Gaver)
// To: blufox@ucscc.UCSC.EDU
// Subject: untab
//
// Al:  Here is a facility to untab.  I'm not a big fan of 'do'
// constructs, but the one in untab() itself seems to lack elegant
// replacements.  I found the basis for this in a hacker's forum,
// so the ideas are not all my own. I gave this and c_align the
// acid test: one of Hitchner's files - things worked out fine.
// With a bit of thought, perhaps untabbing and aligning can take
// place in only one pass.
//
//    Harry
//

#include "c_align.h"

void untab(cchr* fname)
{
   char       tfn[maxstring];                             // tmp filename
   char       ch;
   int        cnt;
   no_yes     cflt;                              // check for leading tab
   ifstream   ifs;
   ofstream   ofs;
    
   ifs.open(fname);
   assert(ifs);
   tmpnam(tfn);
   ofs.open(tfn);
   assert(tfn);
   cnt = 0;
   cflt = yes;
   ifs.unsetf(ios::skipws);                    // do not skip white space
   while (ifs >> ch) {
      if (ch == '\n') {
         ofs << ch;
         cnt = 0;                                    // reset cnt to zero
         cflt = yes;
      }
      else if (ch == '\t' && cflt == yes) {
         ofs << ch;
         cnt += 8;
      }
      else if (ch == '\t') {
         do {
            ofs << ' ';
            ++cnt;
         } while (cnt % tabstop);                    // tabstop is global
      }
      else if (isprint(ch) || iscntrl(ch)) {
         ofs << ch;
         ++cnt;
         cflt = no;
      }
   }
   ifs.close();
   ofs.close();
   copy(tfn, fname);
   gremove(tfn);
}

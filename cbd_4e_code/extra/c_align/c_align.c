#include "c_align.h"

void c_align(cchr* fname, cchr* tfn)
{
   char       line[maxline];
   char       save[maxline];
   char       ch;
   char*      p;
   cchr*      q;
   int        cnt;
   int        cnt_save;
   ifstream   ifs(fname);
   ofstream   ofs(tfn);

   assert(ifs);
   assert(ofs);
   untab(fname);                              // only leading tabs remain
   cnt = 0;
   while (ifs.getline(line, maxline)) {
      ++cnt;
      strcpy(save, line);                    // save for possible trouble
      cnt_save = cnt;
      //
      // Skip leading white space and then check for comments.
      // If a comment is found, it is not adjustable.
      // Just leave it as it is.
      //
      for (p = line; *p == ' ' || *p == '\t'; ++p)
         ;
      if (strncmp(p, "//", 2) == 0) {
         //
         // C++ style comment found.
         //
         ofs << line << "\n";
         continue;
      }
      if (strncmp(p, "/*", 2) == 0) {
         //
         // Beginning of a C style comment found.
         // Look for its end.
         //
         ofs << line << "\n";
         if (strstr(p + 2, "*/") == NULL) {
            while (ifs.getline(line, maxline)) {
               ++cnt;
               ofs << line << "\n";
               if (strstr(line, "*/") != NULL)
                  break;
            }
            if (!ifs) {
               wrapup(ifs, ofs, tfn);
               error_exit_comment_not_closed(fname, cnt_save, save);
            }
         }
         continue;
      }
      //
      // ---
      // Now each character in the line must be checked.
      // Character constants and string constants are passed over.
      // Comments found at the end of the line are considered adjustable.
      // Any // style comment found at the end of a #define line is changed
      // to a /* ... */ comment.  This helps to guard against inadvertently
      // killing code at the end of a line.
      //
      // ---
      // This for loop is unwieldy, but I have not found a better scheme.
      //
      for ( ; *p != '\0'; ++p) {
         if (*p == '\'' || *p == '"') {
            ch = *p;
            p = move_to_closing_char(p);
            if (*p == '\0') {
               wrapup(ifs, ofs, tfn);
               error_exit_closing_char_not_found(fname, ch, cnt, line);
            }
            //
            // At this point p is pointing to the closing char.
            // Note carefully, however, it will be incremented at
            // the end of the for loop.
            //
            assert(*p == '\'' || *p == '"');
         }
         else if (strncmp(p, "//", 2) == 0) {
            //
            // Here is where p shows its true colors:
            //
            //    char*       not       cchr*
            //
            adjust_comment(fname, cnt, line, p);
            break;
         }
         else if (strncmp(p, "/*", 2) == 0) {
            //
            // Look for the closing */ on this line.
            //
            if ((q = strstr(p + 2, "*/")) != NULL) {
               for (q += 2; isspace(*q); ++q)
                  ;
               if (*q == '\0')
                  adjust_comment(fname, cnt, line, p);
            }
            else {
               //
               // A comment on the right need not be adjustable.
               // Here is an example of such a comment:
               //
               //    dbl   x;   /* This variable
               //                  is very special. */
               //
               ofs << line << "\n";
               while (ifs.getline(line, maxline)) {
                  //
                  // CAUTION:
                  //    The current line gets written on for loop exit.
                  //
                  ++cnt;
                  if (strstr(line, "*/") != NULL)
                     break;
                  ofs << line << "\n";
               }
               if (!ifs) {
                  wrapup(ifs, ofs, tfn);
                  error_exit_comment_not_closed(fname, cnt_save, save);
               }
            }
            //
            // After finding /* do not process any more chars.
            //
            break;
         }
      }
      ofs << line << "\n";
   }
   ifs.close();
   ofs.close();
}

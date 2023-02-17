// ---
// The argument cp is pointing at a short comment in line
// that can be adjusted.  If it is in a #define line,
// force the comment style to be /* ... */.
//

#include "c_align.h"

void adjust_comment(cchr* fname, int cnt, char* line, char* cp)
{
   cchr*   place = "adjust_comment()";

   char    comment[maxline];
   cchr*   p;
   char*   q;
   int     n;
   int     len;
   kcs     style;                                // kind of comment style
   kcs     requested;                            // kind of comment style

   //
   // Capture the comment without beginning or ending white space.
   //
   strcpy(comment, cp);
   strip(comment);
   //
   // Check for errors.
   //
   style = get_comment_style(comment);
   if (style == error)
      error_exit_not_a_comment(fname, cnt, line, comment);
   if (style == mixed)
      error_exit_mixed_comment(fname, cnt, line, comment);
   //
   // Make changes of the following kind:
   //
   //    from: //pretty up       to: // pretty up
   //    from: /*pretty up*/     to: /* pretty up */
   //
   pretty_up(comment, style);
   //
   // Change the comment style, if necessary.
   //
   if (o.style_option()) {
      requested = o.get_style();
      if (style != requested) {
         change_comment_style(comment);
         if (style == c)
            style = cpp;
         else if (style == cpp)
            style = c;
         else
            error_exit_cannot_get_here(place);
      }
   }
   if (style == cpp && is_define_line(line) == yes)
      change_comment_style(comment);
   //
   // Put the comment on the right.
   //
   assert(cp > line);
   len = 0;
   for (p = line; *p == '\t'; ++p)
      len += tabstop;
   for (q = cp - 1; q >= line && isspace(*q); --q)
      ;
   ++q;
   len += q - p;
   n = strlen(comment);
   for (len += n; len < right_edge; ++len)
      *q++ = ' ';
   strcpy(q, comment);
}

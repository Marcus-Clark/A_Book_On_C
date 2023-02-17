#include "c_align.h"

void change_comment_style(char* comment)
{
   cchr*   place = "change_comment_style()";

   char*   p;
   int     n;

   //
   // The comment has already been stripped.
   //
   if (strncmp(comment, "/*", 2) == 0) {
      *(comment + 1) = '/';
      n = strlen(comment);
      p = comment + n - 2;
      assert(strncmp(p, "*/", 2) == 0);
      for (--p; isspace(*p); --p)
         ;
      *++p = '\0';
   }
   else if (strncmp(comment, "//", 2) == 0) {
      *(comment + 1) = '*';
      n = strlen(comment);
      p = comment + n;
      strcpy(p, " */");
   }
   else
      error_exit_cannot_get_here(place);
}

void copy(cchr* from, cchr* to)
{
   char       line[maxline];
   ifstream   ifs;
   ofstream   ofs;

   ifs.open(from);
   if (!ifs)
      error_exit_cannot_open(from);
   ofs.open(to);
   if (!ofs)
      error_exit_cannot_open(to);
   while (ifs.getline(line, maxline))
      ofs << line << "\n";
   ifs.close();
   ofs.close();
}

kcs get_comment_style(cchr* comment)
{
   int   n;
   kcs   style;                                  // kind of comment style

   //
   // The comment has already been stripped
   // of leading and ending white space.
   //
   n = strlen(comment);
   if (strncmp(comment, "//", 2) == 0) {
      if (strncmp(comment + n - 2, "*/", 2) == 0)
         style = mixed;
      else
         style = cpp;
   }
   else if (strncmp(comment, "/*", 2) == 0) {
      assert(strncmp(comment + n - 2, "*/", 2) == 0);
      style = c;
   }
   else
      style = error;
   return style;
}

no_yes is_blank(cchr* line)
{
   cchr*   p;

   for (p = line; *p != '\0'; ++p) {
      if (!isspace(*p))
         return no;
   }
   return yes;
}


no_yes is_define_line(cchr* line)
{
   cchr*   p;

   for (p = line; isspace(*p); ++p)
      ;
   if (strncmp(p, "#define", 7) == 0)
      return yes;
   return no;
}

char* move_to_closing_char(char* p)
{
   cchr   ch = *p;
   int    backslash_cnt;

   assert(ch == '\'' || ch == '"');
   //
   // Inside single quotes \' is not closing, but \\' is.
   // Similarly, inside a string \" is not closing, but \\" is.
   // Therefore, a count of the preceeding backslashes is needed.
   //
   backslash_cnt = 0;
   for (++p; *p != '\0' && (*p != ch || backslash_cnt % 2 == 1); ++p) {
      if (*p == '\\')
         ++backslash_cnt;
      else
         backslash_cnt = 0;
   }
   assert(*p == ch || *p == '\0');
   return p;
}

void pretty_up(char* comment, kcs style)
{
   char*   p;
   char*   q;
   char*   r;
   int     n;

   assert(style == cpp || style == c);
   //
   // Leading and ending white space has already been stripped.
   //
   assert(!isspace(*comment));
   n = strlen(comment);
   assert(!isspace(*(comment + n - 1)));
   //
   // A degenerate comment such as
   //
   //    //
   //
   // is allowed.
   //
   if (n == 2)
      return;                                                   // return
   //
   // After // or /* we want precisely one blank character.
   //
   assert(n > 2);
   p = comment;
   for (q = p + 2; isspace(*q); ++q)
      ;
   if (q - p != 3) {
      ostrstream   oss;
      oss << *p << *(p + 1) << ' ' << q << ends;
      r = oss.str();
      strcpy(comment, r);
      delete [] r;
   }
   if (style == c) {
      //
      // Before */ we want precisely one blank character.
      //
      q = strstr(comment, "*/");
      assert(q != NULL);
      for (p = q - 1; isspace(*p); --p)
         ;
      if (q - p != 2)
         strcpy(p + 1, " */");
   }
}

cchr* report(kcs val)
{
   cchr*   s;

   switch (val) {
   case c:
      s = "c";
      break;
   case cpp:
      s = "cpp";
      break;
   case mixed:
      s = "mixed";
      break;
   case none:
      s = "none";
      break;
   case error:
      s = "error";
      break;
   default:
      cout << "PROGRAMMER ERROR: In report() - bye!\n\n";
      exit(1);
   }
   return s;
}

cchr* report(off_on val)
{
   return ((val == off) ? "off" : "on");
}

void strip(char* s)
{
   char*   p;
   int     i;
   int     n;

   //
   // Remove trailing white space.
   //
   n = strlen(s);
   for (p = s + n - 1; p >= s && isspace(*p); --p)
      ;
   *++p = '\0';
   //
   // Remove leading white space.
   //
   for (p = s; isspace(*p); ++p)
      ;
   if (p > s) {
      i = 0;
      for ( ; *p != '\0'; ++p)
         s[i++] = *p;
      s[i] = '\0';
   }
}

void view(cchr* tfn)
{
   char         answer[maxword];
   char         line[maxline];
   char*        cmnd;
   ostrstream   oss;

   assert(o.test_option());
   cout << "---\n"
           "TEST OPTION:\n"
           "   \n"
           "   Ready to view the tmp file " << tfn << "? ";
   cin.getline(line, maxline);
   istrstream   iss(line);
   cout << "\n";
   iss >> answer;
   if (!iss || *answer == 'y' || *answer == 'Y') {
      oss << "vi " << tfn << ends;
      cmnd = oss.str();
      gsystem(cmnd);
      delete [] cmnd;
      cout << "\n";
   }
}

void wrapup(ifstream& ifs, ofstream& ofs, cchr* tfn)
{
   ifs.close();
   ofs.close();
   gremove(tfn);
}

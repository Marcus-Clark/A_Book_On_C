#include "wrt_char.h"

cchr* action::bit_print(char v)
{
   int                 i;
   static char         buf[maxstring];
   static ostrstream   oss(buf, maxstring);

   static int          n    = CHAR_BIT;                    // in limits.h
   static int          mask = 1 << (n - 1);             // mask = 100...0

   grewind(oss);
   for (i = 1; i <= n; ++i) {
      //
      // Caution: Operator precedence!
      //
      oss << (((v & mask) == 0) ? '0' : '1');
      v <<= 1;
   }
   oss << ends;
   return oss.str();
}

void action::runrun()
{
   int   i;
   int   k;

   //
   // I tried the following command, which effects
   // the printing of the hexadecimal and octal
   // numbers, but did not like the effect:
   //
   //    cout.setf(ios::showbase);
   //
   cin.unsetf(ios::skipws);
   if (o.wrt_everything_option()) {
      if (isatty(1)) {
         //
         // The following are global variables:
         //
         //       mnl = minimum number of lines
         //    nlines = number of lines in the current xterm window
         //
         assert(mnl == 17);
         assert(nlines >= mnl);
         k = nlines - 5;
         for (i = 0; i < 256; ++i) {
            if ((i + k - 13) % k == 0)
               wrt_my_more();
            c = (unsigned char) i;
            wrt_char();
         }
      }
      else {
         for (i = 0; i < 256; ++i) {
            c = (unsigned char) i;
            wrt_char();
         }
      }
   }
   else if (o.alt_input_option()) {
      while (cin >> k && k >= 0 && k <= 255) {
         c = (unsigned char) k;
         wrt_char();
      }
   }
   else {
      prev = 255;                                     // turn all bits on
      cnt = 1;
      for ( ; ; ) {
         cin >> c;
         if (c == prev)
            ++cnt;
         else
            cnt = 1;
         prev = c;
         wrt_char();
         if (cnt == 3)
            break;
      }
   }
}

void action::set_heading(cchr**& h, int& len, int& sz)
{
   //
   // Here are three possible header names:
   //
   //    bits
   //    bit print
   //    bit representation
   //
   // Technically, the last name is the most appropriate.
   // Is it so long that it detracts from the aesthetics
   // of the printout?  I will code it two ways.
   //

   off_on   use_bit_representation = off;

   if (use_bit_representation == on) {
      len = 18;                                 // length of each heading
      sz  = 18;                                     // number of headings
      h   = new cchr* [sz];                          // array of headings

      h[ 0] = "character         ";
      h[ 1] = "decimal           ";
      h[ 2] = "hexadecimal       ";
      h[ 3] = "octal             ";
      h[ 4] = "ascii name        ";
      h[ 5] = "bit representation";                // a very long heading
      h[ 6] = "isalpha           ";
      h[ 7] = "isupper           ";
      h[ 8] = "islower           ";
      h[ 9] = "isdigit           ";
      h[10] = "isxdigit          ";
      h[11] = "isalnum           ";
      h[12] = "isspace           ";
      h[13] = "ispunct           ";
      h[14] = "isprint           ";
      h[15] = "isgraph           ";
      h[16] = "iscntrl           ";
      h[17] = "isascii           ";
   }
   else {
      //
      // Here we are using "bit print" as a heading
      // instead of "bit representation" which is
      // too long for decent printout.
      //
      len = 11;                                 // length of each heading
      sz  = 18;                                     // number of headings
      h   = new cchr* [sz];                          // array of headings

      h[ 0] = "character  ";
      h[ 1] = "decimal    ";
      h[ 2] = "hexadecimal";
      h[ 3] = "octal      ";
      h[ 4] = "ascii name ";
      h[ 5] = "bit print  ";                         // poor heading name
      h[ 6] = "isalpha    ";
      h[ 7] = "isupper    ";
      h[ 8] = "islower    ";
      h[ 9] = "isdigit    ";
      h[10] = "isxdigit   ";
      h[11] = "isalnum    ";
      h[12] = "isspace    ";
      h[13] = "ispunct    ";
      h[14] = "isprint    ";
      h[15] = "isgraph    ";
      h[16] = "iscntrl    ";
      h[17] = "isascii    ";
   }
}

void action::wrt_char()
{
   char*               p;
   field_width         fw;
   static const uint   del  = 0177;                       // del = delete
   static const uint   mask = 127;            // turn 7 low-order bits on

   //
   // Should the ascii name be right or left adjusted?
   // This is a style question.  I will provide code
   // here to do it either way.
   //
   off_on   right_adjust_ascii_name = on;
   //
   // The unsigned char c and the unsigned int cc
   // are private memebers of the class.
   //
   cc = c;
   //
   // We do not expect bits 8-31 to be on.
   //
   assert(cc | mask == mask);
   //
   // The char ' ' has decimal value 32.
   //
   if (c <= 32)
      cout << fw(4) << repr[c];
   else if (c == del)
      cout << fw(4) << "^?";
   else if (c >= 128 && c <= 160) {
      //
      // Characters in this range do not print on the screen but
      // they do print as \2?? when the output is redirected to
      // a file.  We want everything to line up properly.
      //
      if (isatty(1))
         cout << fw(4) << "";
      else
         cout << c;
   }
   else if (c >= 161 && c <= 255) {
      //
      // Characters in this range do print on the screen
      // but when redirected to a file print as \2??.
      //
      if (isatty(1)) {
         ostrstream   oss;
         oss << c << ends;
         p = oss.str();
         cout << fw(4) << p;
         delete [] p;
      }
      else
         cout << c;
   }
   else {
      //
      // Has the functionality of setw() been changed?
      // Both CC and g++ disagree with page 10 of
      //
      //    C++ IOStreams by Steve Teale
      //
      // See the following test program:
      //
      //    $cex/setw_2.c
      //
      ostrstream   oss;
      oss << c << ends;
      p = oss.str();
      cout << fw(4) << p;
      delete [] p;
   }
   cout << fw(6) << dec << cc
        << fw(5) << hex << cc
        << fw(6) << oct << cc
        << dec;                                       // reset to decimal
   //
   // Everything is right adjusted in its field,
   // except possibly for the ascii name, which
   // can be either 0, 2, or 3 characters.
   // What is the preferred style?
   //
   if (right_adjust_ascii_name == off)
      cout.setf(ios::left, ios::adjustfield);
   if (c <= 32) {
      cout << "   " << fw(3) << name[c];
   }
   else if (c == del)
      cout << "   " << fw(3) << "del";
   else
      cout << "   " << fw(3) << "";
   if (right_adjust_ascii_name == off)
      cout.setf(ios::right, ios::adjustfield);
   //
   // Bit print the character.
   //
   // Note that bit_print() works on a copy of c, so that
   // in the calling environment c does not get changed.
   //
   cout << fw(11) << bit_print(c);
   //
   // Report all the ctypes next and end the line.
   //
   cout << fw(4) << report(isalpha(c))
        << fw(4) << report(isupper(c))
        << fw(4) << report(islower(c))
        << fw(4) << report(isdigit(c))
        << fw(4) << report(isxdigit(c))
        << fw(4) << report(isalnum(c))
        << fw(4) << report(isspace(c))
        << fw(4) << report(ispunct(c))
        << fw(4) << report(isprint(c))
        << fw(4) << report(isgraph(c))
        << fw(4) << report(iscntrl(c))
        << fw(4) << report(isascii(c))
        << "\n";
}

void action::wrt_heading()
{
   char           line[maxline];
   char           tfn[maxstring];                         // tmp filename
   char*          p;
   int            i;
   int            j;
   int            k;
   ifstream       ifs;
   ofstream       ofs;

   cchr**         h;                                 // array of headings
   int            len;                          // length of each heading
   int            sz;                               // number of headings
   field_width*   fw;                            // array of field widths

   //
   // Here are three possible header names:
   //
   //    bits
   //    bit print
   //    bit representation
   //
   // The choice is made in the next function call.
   //
   set_heading(h, len, sz);
   assert(strlen(h[0]) == (unsigned) len);

   //
   // The array element fw[i] contains the number of spaces that gets
   // printed before a character in the ith heading gets printed.
   //         ------
   //
   // Because setw() does not work on char output,
   // we work with the space between characters
   // rather than the field width as a whole.
   //
   fw = new field_width [sz];

   fw[ 0].set(1);
   fw[ 1].set(5);
   fw[ 2].set(4);
   fw[ 3].set(5);
   fw[ 4].set(5);
   fw[ 5].set(10);
   fw[ 6].set(3);
   fw[ 7].set(3);
   fw[ 8].set(3);
   fw[ 9].set(3);
   fw[10].set(3);
   fw[11].set(3);
   fw[12].set(3);
   fw[13].set(3);
   fw[14].set(3);
   fw[15].set(3);
   fw[16].set(3);
   fw[17].set(3);

   assert(sz == 17 + 1);

   //
   // The lines we write will end with blanks,
   // which is not good.  To get around this
   // problem, we first write to a tmp file.
   //
   tmpnam(tfn);
   ofs.open(tfn);
   assert(tfn);
   k = len + 1;
   for (j = len - 1; j >= 0; --j) {
      ofs << setw(k--) << "";
      for (i = 0; i < sz; ++i)
         ofs << fw[i] << "" << h[i][j];
      ofs << "\n";
   }
   //
   // Write a line of dashes to separate
   // the heading from the main output.
   //
   // The following variable is global
   //
   //    mnc = minimum number of columns
   //
   for (i = 1; i <= mnc; ++i)
      ofs << "-";
   ofs << "\n";
   ofs.close();
   //
   // Remove ending blanks on each line
   // before printing it to the screen.
   //
   ifs.open(tfn);
   assert(ifs);
   while (ifs.getline(line, maxline)) {
      p = line + strlen(line) - 1;
      for ( ; p > line && isspace(*p); --p)
         ;
      assert(p >= line);
      *++p = '\0';
      cout << line << "\n";
   }
   ifs.close();
   gremove(tfn);
}

// ---
// This program is delicate in the sense that what one sees on the
// screen varies with the both the command and the system.  Getting
// it all to line up properly seems to be a Herculean task.
// Consider the following commands:
//
//    wrt_char -e
//    wrt_char -e > out
//    wrt_char -e | more
//
// Piping through more on a Sun SparcStation 10 running Solaris 7
// causes lines like the following to be printed on the screen
// [[according to Peter Scott, this is not the case on his
// linux machine]]:
//
//    M-^^   158   9e   236         10011110   0   0   0   .....
//    M-^_   159   9f   237         10011111   0   0   0   .....
//    M-    160   a0   240         10100000   0   0   0   .....
//    M-!   161   a1   241         10100001   0   0   0   .....
//
// I would like to make this output line up properly, but here is the
// problem.  Although the more utility sees a single character, if that
// character is in the range 128 to 255, what gets printed on the screen
// is M-?? where ?? is either one or two characters.  This conflicts with
// what happens on redirection.  In that case, when viewed with vi, we
// see \200, \201, etc.  These are all four characters each, so lining
// things up is not a problem.
//
// In a [[probably vain]] attempt to keep the user from piping the
// output through more, we provide that functionality ourselves.
//

void action::wrt_my_more()
{
   char   line[maxline];
   char   s[maxstring];

   assert(isatty(1));
   cout << "\n--- more more more ---\n";
   cin.getline(line, maxline);
   istrstream   iss(line);
   iss >> s;
   if (iss && (*s == 'q' || *s == 'Q'))
      exit(1);
}

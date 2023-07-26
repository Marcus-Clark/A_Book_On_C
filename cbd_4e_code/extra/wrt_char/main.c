#include "wrt_char.h"

// ---
// Control character representations.
//

cchr* repr[] = {
   "^@",  "^A",  "^B",  "^C",  "^D",  "^E",  "^F",  "^G",
   "^H",  "^I",  "^J",  "^K",  "^L",  "^M",  "^N",  "^O",
   "^P",  "^Q",  "^R",  "^S",  "^T",  "^U",  "^V",  "^W",
   "^X",  "^Y",  "^Z",  "^[",  "^\\",  "^]",  "^^",  "^_",
   " "
};

// ---
// Control character names.
//

cchr* name[] = {
   "nul",  "soh",  "stx",  "etx",  "eot",  "enq",  "ack",  "bel",
   "bs",   "ht",   "nl",   "vt",   "np",   "cr",   "so",   "si",
   "dle",  "dc1",  "dc2",  "dc3",  "dc4",  "nak",  "syn",  "etb",
   "can",  "em",   "sub",  "esc",  "fs",   "gs",   "rs",   "us",
   "sp"
};

int       ncols  = -1;            // # of columns in current xterm window
int       nlines = -1;              // # of lines in current xterm window
options   o;                                        // options are global

int main(int argc, char** argv)
{
   termios   t;
   termios   sv;
   action    a;

   o.get_options(argc, argv);
   //
   // If the current xterm window is not big enough, then
   // the output of this program is very difficult to read.
   // So, if the user is writing to the screen and the
   // window is too small, exit with a message.
   //
   if (isatty(1))
      chk_xterm_window();
   //
   // If the wrt_everything option is on,
   // there is no need for a hot keyboard.
   //
   if (o.wrt_everything_option()) {
      a.wrt_heading();
      a.runrun();
   }
   else {
      //
      // Here is where we borrow ideas
      // from the ascii program that
      // Peter Scott sent to me.
      //
      // The keyboard is hot.
      //                 ---
      //
      gtcgetattr(0, &t);                       // get current terminal state
      sv = t;                                      // save the current state
      set_bits(t);
      wrt_msg_to_user();
      gtcsetattr(0, TCSANOW, &t);                   // make the keyboard hot
      a.wrt_heading();
      a.runrun();
      gtcsetattr(0, TCSANOW, &sv);                 // restore terminal state
   }
   cout << "\n";
}

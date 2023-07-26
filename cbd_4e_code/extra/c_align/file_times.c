#include "c_align.h"

void get_file_times(cchr* fn, int& la_ac_ti, int& la_mo_ti)
{
   cchr*&        fname = fn;
   int&          last_access_time = la_ac_ti;
   int&          last_modify_time = la_mo_ti;
   struct stat   statbuf;

   gstat(fname, &statbuf);
   last_access_time = statbuf.st_atime;
   last_modify_time = statbuf.st_mtime;
}

void restore_file_times(cchr* fn, int la_ac_ti, int la_mo_ti)
{
   cchr*&           fname = fn;
   int&             last_access_time = la_ac_ti;
   int&             last_modify_time = la_mo_ti;
   struct timeval   tvp[2];

   tvp[0].tv_sec = last_access_time;               // prepare to backdate
   tvp[1].tv_sec = last_modify_time;
   tvp[0].tv_usec = tvp[1].tv_usec = 0;
   gutimes(fname, tvp);                              // backdate the file
}

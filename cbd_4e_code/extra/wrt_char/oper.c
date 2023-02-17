#include "wrt_char.h"

ostream& operator<<(ostream& os, field_width fw)
{
   os.width(fw.value());
   return os;
}

ios& left(ios& s)
{
   s.setf(ios::left, ios::adjustfield);
   return s;
}

ios& right(ios& s)
{
   s.setf(ios::right, ios::adjustfield);
   return s;
}

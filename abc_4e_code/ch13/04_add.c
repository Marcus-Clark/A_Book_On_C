// Use of a default value.

#include <iostream.h>

inline void add3(int& s, int a, int b, int c = 0)
{
   s = a + b + c;
}

inline double average(int s) { return s / 3.0; }

int main()
{
   int   score_1, score_2, score_3, sum;

   cout << "\nEnter 3 scores: ";
   cin >> score_1 >> score_2 >> score_3;
   add3(sum, score_1, score_2, score_3);
   cout << "\nSum = " << sum;
   cout << "\nAverage = " << average(sum) << endl;
   add3(sum, 2 * score_1, score_2);  // use of default value 0
   cout << "\nWeighted Sum = " << sum << ".";
   cout << "\nWeighted Average = " << average(sum) << ".\n"; 
}

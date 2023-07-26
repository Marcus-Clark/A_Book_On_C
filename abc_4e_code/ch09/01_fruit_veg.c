#include <stdio.h>

int main(void)
{
   struct fruit {
      char   *name;
      int    calories;
   };

   struct vegetable {
      char   *name;
      int    calories;
   };

   struct fruit       a;
   struct vegetable   b;

   a.name = "apple";
   a.calories = 153;
   b.name = "broccoli";
   b.calories = 79;
   printf("%s%s%s%d%s%s%s%d%s",
      "---\n"
      "Fruit:\n"
      "       name: ", a.name, "\n"
      "   calories: ", a.calories, "\n"
      "\n"
      "---\n"
      "Vegetable:\n"
      "       name: ", b.name, "\n"
      "   calories: ", b.calories, "\n"
      "\n");
   return 0;
}

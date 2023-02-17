#include "p_r_s.h"

int main(void)
{
   int       win_cnt = 0, lose_cnt = 0, tie_cnt = 0;
   outcome   result;
   p_r_s     player_choice, machine_choice;

   srand(time(NULL));     /* seed the random number generator */
   wrt_instructions();
   while ((player_choice = selection_by_player()) != quit)
      switch (player_choice) {
      case paper:
      case rock:
      case scissors:
         machine_choice = selection_by_machine();
       result = compare(player_choice, machine_choice);
       report_and_tabulate(result, &win_cnt, &lose_cnt,
                           &tie_cnt);
         break;
      case game:
         wrt_game_status(win_cnt, lose_cnt, tie_cnt);
         break;
      case instructions:
         wrt_instructions();
         break;
      case help:
         wrt_help();
         break;
      default:
       printf("\nPROGRAMMER ERROR: Cannot get to here!\n\n");
       exit(1);
      }
   wrt_game_status(win_cnt, lose_cnt, tie_cnt);
   wrt_final_status(win_cnt, lose_cnt);
   return 0;
}

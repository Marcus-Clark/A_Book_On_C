#include "p_r_s.h"

void wrt_final_status(int win_cnt, int lose_cnt)
{
   if (win_cnt > lose_cnt)
      printf("CONGRATULATIONS - You won!\n\n");
   else if (win_cnt == lose_cnt)
      printf("A DRAW - You tied!\n\n");
   else
      printf("SORRY - You lost!\n\n");
}

void wrt_game_status(int win_cnt, int lose_cnt, int tie_cnt)
{
   printf("\n%s\n%s%4d\n%s%4d\n%s%4d\n%s%4d\n\n",
      "GAME STATUS:",
      "   Win:   ", win_cnt,
      "   Lose:  ", lose_cnt,
      "   Tie:   ", tie_cnt,
      "   Total: ", win_cnt + lose_cnt + tie_cnt);
}

void wrt_help(void)
{
   printf("\n%s\n",
      "The following characters can be used for input:\n"
      "     p   for paper\n"
      "     r   for rock\n"
      "     s   for scissors\n"
      "     g   print the game status\n"
      "     h   help, print this list\n"
      "     i   reprint the instructions\n"
      "     q   quit this game\n");
}

void wrt_instructions(void)
{
   printf("\n%s\n",
      "PAPER, ROCK, SCISSORS:\n"
      "   In this game p is for \"paper,\" r is for \"rock,\" and"
      " s is for \"scissors.\"\n"
      "   Both the player and the machine\n"
      "   will choose one of p, r, or s."
      "  If the two choices are the same,\n"
      "   then the game is a tie.  Otherwise:\n"
      "      \"paper covers the rock\"     (a win for paper),\n"
      "      \"rock breaks the scissors\"  (a win for rock),\n"
      "      \"scissors cut the paper\"    (a win for scissors).\n"
      "\n"
      "   There are other allowable inputs:\n"
      "      g   for game status   (the number of wins so far),\n"
      "      h   for help,\n"
      "      i   for instructions  (reprint these instructions),\n"
      "      q   for quit          (to quit the game).\n"
      "\n"
      "   This game is played repeatedly until q is entered.\n"
      "\n"
      "   Good luck!\n");
}

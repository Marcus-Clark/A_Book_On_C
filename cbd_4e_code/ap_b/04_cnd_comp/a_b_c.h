#define   MAIN   int main(void)

#if 0
#define   A_B_C                                   \
                                                  \
   Which layout looks best?
   MAIN                                           \
   {                                              \
      printf("\n   A Big Cheery \"hello\"!\n\n"); \
      return 0;                                   \
   }
#endif



#define   A_B_C   MAIN                                           \
                  {                                              \
                     printf("\n   A Big Cheery \"hello\"!\n\n"); \
                     return 0;                                   \
                  }

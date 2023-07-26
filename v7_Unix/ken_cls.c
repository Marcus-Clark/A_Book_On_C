/*
 * cls.c 3-1-2023 KenUnix
 * A simple program to clear the screen and home the cursor
 *
 * cc -o cls cls.c
 * mv cls /usr/bin/.
 * Do not strip it. It weirds out sometimes
 *
*/
#include <stdio.h>

main()
{

/* vt100 clear screen sequence */
/* Raw codes : 033 133 110 033 133 062 112 033 133 063 112 */
printf ("\033\133\110\033\133\062\112\033\133\063\112");

}

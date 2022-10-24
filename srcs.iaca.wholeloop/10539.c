#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __uint32_t uint32_t;

int
fn (_Bool opt_robot, uint32_t checks, const char *sep, char *pos,
    const char check_names[16][12], size_t left, _Bool comma)
{
  IACA_START for (size_t i = 0; i <= 15; ++i)
    {
      if (checks & (1U << i))
	{
	  my_snprintf (&pos, &left, "%s%s", comma ? sep : "",
		       opt_robot ? check_names[i] : (check_names[i]));
	  comma = 1;
	}
     } IACA_END
}

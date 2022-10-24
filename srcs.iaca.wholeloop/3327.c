#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef RangeCoder;
typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (const int a, uint64_t (*rc_stat2)[2], int i, const int e, RangeCoder * c,
    uint8_t * state, uint64_t (*rc_stat)[2])
{
  IACA_START for (i = e - 1; i >= 0; i--)
    {
      do
	{
	  if (rc_stat)
	    {
	      rc_stat[*(state + 22 + i)][(a >> i) & 1]++;
	      rc_stat2[(state + 22 + i) - state][(a >> i) & 1]++;
	    }
	  put_rac (c, state + 22 + i, (a >> i) & 1);
	}
      while (0);
     } IACA_END
}

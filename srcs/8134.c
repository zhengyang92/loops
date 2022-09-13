#include <stdint.h>
#include <stdio.h>




typedef RangeCoder;
typedef __uint8_t uint8_t;
typedef __uint64_t uint64_t;

int
fn (uint64_t (*rc_stat2)[2], int i, const int e, RangeCoder * c,
    uint8_t * state, uint64_t (*rc_stat)[2])
{
  for (i = 0; i < e; i++)
    {
      do
	{
	  if (rc_stat)
	    {
	      rc_stat[*(state + 1 + i)][1]++;
	      rc_stat2[(state + 1 + i) - state][1]++;
	    }
	  put_rac (c, state + 1 + i, 1);
	}
      while (0);
    }
}

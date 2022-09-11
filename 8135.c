#include <stdint.h>
#include <stdio.h>




typedef RangeCoder;
typedef __uint8_t uint8_t;
typedef __uint64_t uint64_t;

int
fn (uint64_t (*rc_stat2)[2], int i, const int e, uint64_t (*rc_stat)[2],
    RangeCoder * c, uint8_t * state, const int a)
{
  for (i = e - 1; i >= 0; i--)
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
    }
}

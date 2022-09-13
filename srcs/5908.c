#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int order, const uint8_t * q_ind, const uint16_t table[129],
    int c[15], unsigned int i)
{
  for (i = 0; i < order; i++)
    {
      if (q_ind[i] & 1)
	c[i] = -table[(q_ind[i] >> 1) + 1];
      else
	c[i] = table[q_ind[i] >> 1];
    }
}

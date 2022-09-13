#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t newocc[256], uint32_t occ[256], int i, int m,
    const uint8_t * one_state)
{
  for (m = 1; m < 256; m++)
    if (occ[m])
      {
	newocc[one_state[m]] += occ[m] * (uint64_t) i >> 8;
	newocc[256 - one_state[256 - m]] +=
	  occ[m] * (uint64_t) (256 - i) >> 8;
      }
}

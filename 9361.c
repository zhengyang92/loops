#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int k, const uint16_t * cdf, unsigned int symbol)
{
  for (k = 0; cdf[k] <= symbol; k++);
}

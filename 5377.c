#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (uint16_t * dst, ptrdiff_t stride, uint16_t vo[15], const uint16_t * top,
    int j, uint16_t ve[15])
{
  for (j = 0; j < 16 / 2; j++)
    {
      memcpy (dst + j * 2 * stride, ve + j, (16 - j - 1) * sizeof (uint16_t));
      memset_bpc (dst + j * 2 * stride + 16 - j - 1, top[16 - 1], j + 1);
      memcpy (dst + (j * 2 + 1) * stride, vo + j,
	      (16 - j - 1) * sizeof (uint16_t));
      memset_bpc (dst + (j * 2 + 1) * stride + 16 - j - 1, top[16 - 1],
		  j + 1);
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint8_t uint8_t;

int
fn (int y, int64_t (*sum0)[4], const uint8_t * main_data, int width, int z,
    const int main_stride, const uint8_t * ref_data, int64_t (*sum1)[4],
    const int ref_stride)
{
  for (; z <= y; z++)
    {
      do
	{
	  void *SWAP_tmp = sum1;
	  sum1 = sum0;
	  sum0 = SWAP_tmp;
	}
      while (0);
      ssim_4x4xn_16bit (&main_data[4 * z * main_stride], main_stride,
			&ref_data[4 * z * ref_stride], ref_stride, sum0,
			width);
    }
}

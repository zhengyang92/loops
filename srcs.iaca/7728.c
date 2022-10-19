#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef struct Runbook
{
  unsigned size;
  unsigned bits;
  unsigned run;
} Runbook;
typedef struct Codebook
{
  unsigned bits;
  unsigned size;
} Codebook;
typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int count, const Codebook * const cb, int16_t * data, int width,
    const Runbook * const rb, PutBitContext * pb, const uint16_t * lut,
    int stride)
{
  for (int j = 0; j < stride; j++)
    {
      int16_t index =
	j >= width ? 0 : ((data[j]) >
			  0 ? 1 : -1) * lut[((data[j]) >=
					     0 ? (data[j]) : (-(data[j])))];
      if (index < 0)
	index += 512;
      if (index == 0)
	{
	  count++;
	  continue;
	}
      else if (count > 0)
	{
	  count = put_runcode (pb, count, rb);
	}
      put_bits (pb, cb[index].size, cb[index].bits);
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct GetBitContext
{
  const uint8_t *buffer, *buffer_end;
  int index;
  int size_in_bits;
  int size_in_bits_plus8;
} GetBitContext;
typedef struct GetByteContext
{
  const uint8_t *buffer, *buffer_end, *buffer_start;
} GetByteContext;
typedef struct Model
{
  int16_t cum_prob[256 + 1];
  int16_t weights[256 + 1];
  uint8_t idx2sym[256 + 1];
  int num_syms;
  int thr_weight, threshold;
} Model;
typedef ArithCoder;
typedef PixContext;
typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __uint32_t uint32_t;

int
fn (uint8_t * rgb_dst, int i, int p, ptrdiff_t stride, int width,
    ArithCoder * acoder, const uint32_t * pal, int j, uint8_t * dst,
    PixContext * pctx)
{
  for (i = 0; i < width; i++)
     { IACA_START
      if (!i && !j)
	p = decode_pixel (acoder, pctx, ((void *) 0), 0, 0);
      else
	p =
	  decode_pixel_in_context (acoder, pctx, dst + i, stride, i, j,
				   width - i - 1);
      if (p < 0)
	return p;
      dst[i] = p;
      if (rgb_dst)
	do
	  {
	    ((uint8_t *) (rgb_dst + i * 3))[2] = (pal[p]);
	    ((uint8_t *) (rgb_dst + i * 3))[1] = (pal[p]) >> 8;
	    ((uint8_t *) (rgb_dst + i * 3))[0] = (pal[p]) >> 16;
	  }
	while (0);
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int uni_code, const uint8_t ff_mpeg4_DCtab_chrom[13][2],
    uint8_t uni_DCtab_chrom_len[512], uint16_t uni_DCtab_chrom_bits[512],
    uint8_t uni_DCtab_lum_len[512], int level, int uni_len,
    const uint8_t ff_mpeg4_DCtab_lum[13][2], uint16_t uni_DCtab_lum_bits[512])
{
  IACA_START for (level = -256; level < 256; level++)
    {
      int size, v, l;
      size = 0;
      v = abs (level);
      while (v)
	{
	  v >>= 1;
	  size++;
	}
      if (level < 0)
	l = (-level) ^ ((1 << size) - 1);
      else
	l = level;
      uni_code = ff_mpeg4_DCtab_lum[size][0];
      uni_len = ff_mpeg4_DCtab_lum[size][1];
      if (size > 0)
	{
	  uni_code <<= size;
	  uni_code |= l;
	  uni_len += size;
	  if (size > 8)
	    {
	      uni_code <<= 1;
	      uni_code |= 1;
	      uni_len++;
	    }
	}
      uni_DCtab_lum_bits[level + 256] = uni_code;
      uni_DCtab_lum_len[level + 256] = uni_len;
      uni_code = ff_mpeg4_DCtab_chrom[size][0];
      uni_len = ff_mpeg4_DCtab_chrom[size][1];
      if (size > 0)
	{
	  uni_code <<= size;
	  uni_code |= l;
	  uni_len += size;
	  if (size > 8)
	    {
	      uni_code <<= 1;
	      uni_code |= 1;
	      uni_len++;
	    }
	}
      uni_DCtab_chrom_bits[level + 256] = uni_code;
      uni_DCtab_chrom_len[level + 256] = uni_len;
     } IACA_END
}

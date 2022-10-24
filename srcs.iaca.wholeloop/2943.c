#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const uint8_t ff_mpeg4_DCtab_lum[13][2],
    uint32_t ff_v2_dc_lum_table[512][2],
    uint32_t ff_v2_dc_chroma_table[512][2],
    const uint8_t ff_mpeg4_DCtab_chrom[13][2])
{
  IACA_START for (int level = -256; level < 256; level++)
    {
      int uni_code, uni_len;
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
      uni_code ^= (1 << uni_len) - 1;
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
      ff_v2_dc_lum_table[level + 256][0] = uni_code;
      ff_v2_dc_lum_table[level + 256][1] = uni_len;
      uni_code = ff_mpeg4_DCtab_chrom[size][0];
      uni_len = ff_mpeg4_DCtab_chrom[size][1];
      uni_code ^= (1 << uni_len) - 1;
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
      ff_v2_dc_chroma_table[level + 256][0] = uni_code;
      ff_v2_dc_chroma_table[level + 256][1] = uni_len;
     } IACA_END
}

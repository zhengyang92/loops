#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int diff, int temp, int i, int offset, int ccr_eng, int eng, int exp,
    int16_t * buf, int orig_eng, int start, int ccr)
{
  int index = 18;
  int max_eng = 0x7fff;
  int max_ccr = 0x4000;
  int max_exp = 32;
  for (i = 18; i <= (18 + 127) - 3; i++)
     { IACA_START
      offset--;
      orig_eng +=
	buf[offset] * buf[offset] - buf[offset +
					((60 << 2) / 2)] * buf[offset +
							       ((60 << 2) /
								2)];
      ccr = ff_dot_product (buf + start, buf + offset, ((60 << 2) / 2));
      if (ccr <= 0)
	continue;
      exp = ff_g723_1_normalize_bits (ccr, 31);
      ccr = av_clipl_int32_c ((int64_t) (ccr << exp) + (1 << 15)) >> 16;
      exp <<= 1;
      ccr *= ccr;
      temp = ff_g723_1_normalize_bits (ccr, 31);
      ccr = ccr << temp >> 16;
      exp += temp;
      temp = ff_g723_1_normalize_bits (orig_eng, 31);
      eng = av_clipl_int32_c ((int64_t) (orig_eng << temp) + (1 << 15)) >> 16;
      exp -= temp;
      if (ccr >= eng)
	{
	  exp--;
	  ccr >>= 1;
	}
      if (exp > max_exp)
	continue;
      if (exp + 1 < max_exp)
	goto update;
      if (exp + 1 == max_exp)
	temp = max_ccr >> 1;
      else
	temp = max_ccr;
      ccr_eng = ccr * max_eng;
      diff = ccr_eng - eng * temp;
      if (diff > 0 && (i - index < 18 || diff > ccr_eng >> 2))
	{
	update:index = i;
	  max_exp = exp;
	  max_ccr = ccr;
	  max_eng = eng;
	}
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int *hpf_f, int i, const int16_t * in, int16_t * out, int tmp, int length)
{
  for (i = 0; i < length; i++)
    {
      tmp = (hpf_f[0] * 15836LL) >> 13;
      tmp += (hpf_f[1] * -7667LL) >> 13;
      tmp += 7699 * (in[i] - 2 * in[i - 1] + in[i - 2]);
      out[i] = av_clip_int16_c ((tmp + 0x800) >> 12);
      hpf_f[1] = hpf_f[0];
      hpf_f[0] = tmp;
    }
}

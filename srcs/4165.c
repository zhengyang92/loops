#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * samples, int count, int i, int HDCD_ANA_PE, int HDCD_ANA_CDT,
    int extend, int HDCD_ANA_TGM, int cdt_active, int mode, int tg_mismatch,
    int stride)
{
  for (i = 0; i < count; i++)
    {
      samples[i * stride] *= 1 << 15;
      if (mode == HDCD_ANA_PE)
	{
	  int pel = (samples[i * stride] >> 16) & 1;
	  int32_t sample = samples[i * stride];
	  samples[i * stride] =
	    hdcd_analyze_gen (sample, !!(pel && extend), 1);
	}
      else if (mode == HDCD_ANA_TGM && tg_mismatch > 0)
	samples[i * stride] = hdcd_analyze_gen (samples[i * stride], 1, 1);
      else if (mode == HDCD_ANA_CDT && cdt_active)
	samples[i * stride] = hdcd_analyze_gen (samples[i * stride], 1, 1);
    }
}

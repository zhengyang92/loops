#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct ADPCMChannelStatus
{
  int predictor;
  int16_t step_index;
  int step;
  int prev_sample;
  int sample1;
  int sample2;
  int coeff1;
  int coeff2;
  int idelta;
} ADPCMChannelStatus;
typedef PutBitContext;
typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int64_t error, ADPCMChannelStatus * cs, int flag, const int16_t * samples,
    PutBitContext * pb, int shift, int nsamples)
{
  for (int n = 0; n < nsamples; n++)
    {
      int nibble = adpcm_argo_compress_nibble (cs, samples[n], shift, flag);
      int16_t sample = ff_adpcm_argo_expand_nibble (cs, nibble, shift, flag);
      error += abs (samples[n] - sample);
      if (pb)
	put_bits (pb, 4, nibble);
    }
}

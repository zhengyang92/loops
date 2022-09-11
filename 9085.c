#include <stdint.h>
#include <stdio.h>




typedef struct ADPCMChannelStatus
{
  int predictor;
  int16_t step_index;
  int step;
  int prev_sample;
  int16_t sample1;
  int16_t sample2;
  int coeff1;
  int coeff2;
  int idelta;
} ADPCMChannelStatus;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int j, const int16_t * smp, ADPCMChannelStatus * status, uint8_t * dst)
{
  for (j = 0; j < 8; j += 2)
    {
      uint8_t v = adpcm_ima_compress_sample (status, smp[j]);
      v |= adpcm_ima_compress_sample (status, smp[j + 1]) << 4;
      *dst++ = v;
    }
}

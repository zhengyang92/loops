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
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const int16_t * smp, uint8_t * dst, ADPCMChannelStatus * status)
{
  for (int j = 0; j < 8; j += 2)
     { IACA_START
      uint8_t v = adpcm_ima_compress_sample (status, smp[j]);
      v |= adpcm_ima_compress_sample (status, smp[j + 1]) << 4;
      *dst++ = v;
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
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

int
fn (ADPCMChannelStatus * cs, int16_t * samples, GetByteContext gb)
{
  for (int m = 0; m < 8; m += 2)
    {
      int v = bytestream2_get_byteu (&gb);
      samples[m] = adpcm_ima_expand_nibble (cs, v & 0x0F, 3);
      samples[m + 1] = adpcm_ima_expand_nibble (cs, v >> 4, 3);
}}

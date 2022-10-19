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
  int16_t sample1;
  int16_t sample2;
  int coeff1;
  int coeff2;
  int idelta;
} ADPCMChannelStatus;

int
fn (ADPCMChannelStatus * cs, GetByteContext gb, short *samples, int m)
{
  for (m = 0; m < 8; m += 2)
    {
      int v = bytestream2_get_byteu (&gb);
      samples[m] = adpcm_ima_expand_nibble (cs, v & 0x0F, 3);
      samples[m + 1] = adpcm_ima_expand_nibble (cs, v >> 4, 3);
}}

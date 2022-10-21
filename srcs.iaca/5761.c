#include "../iacaMarks.h"
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
typedef PutBitContext;
typedef __int16_t int16_t;

int
fn (int16_t ** samples_p, int i, int ch, PutBitContext pb,
    ADPCMChannelStatus * status)
{
  for (i = 0; i < 64; i += 2)
     { IACA_START
      int t1, t2;
      t1 = adpcm_ima_qt_compress_sample (status, samples_p[ch][i]);
      t2 = adpcm_ima_qt_compress_sample (status, samples_p[ch][i + 1]);
      put_bits (&pb, 4, t2);
      put_bits (&pb, 4, t1);
} IACA_END }

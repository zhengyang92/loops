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

int
fn (int16_t ** samples_p, PutBitContext pb, ADPCMChannelStatus * status)
{
  int ch = 0;
  for (int i = 0; i < 64; i += 2)
    {
      int t1, t2;
      t1 = adpcm_ima_qt_compress_sample (status, samples_p[ch][i]);
      t2 = adpcm_ima_qt_compress_sample (status, samples_p[ch][i + 1]);
      put_bits (&pb, 4, t2);
      put_bits (&pb, 4, t1);
}}

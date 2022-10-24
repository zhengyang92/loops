#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t acb_vector[60], int j, int16_t * vector_ptr)
{
  IACA_START for (j = 0; j < 60; j++)
    {
      int v = av_clip_int16_c (vector_ptr[j] * 2);
      vector_ptr[j] = av_clip_int16_c (v + acb_vector[j]);
}IACA_END}

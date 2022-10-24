#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float postfilter_energy, float speech_energy, int size,
    const float *in, const float *speech_synth)
{
  IACA_START for (i = 0; i < size; i++)
    {
      speech_energy += fabsf (speech_synth[i]);
      postfilter_energy += fabsf (in[i]);
     } IACA_END
}

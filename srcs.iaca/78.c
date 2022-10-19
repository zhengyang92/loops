#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct amerge_input
{
  int nb_ch;
} amerge_input;
typedef __uint8_t uint8_t;

int
fn (uint8_t ** outs, int i, int *route_cur, struct amerge_input *in, int c,
    uint8_t ** ins, int bps)
{
  for (c = 0; c < in[i].nb_ch; c++)
    {
      memcpy ((*outs) + bps * *(route_cur++), ins[i], bps);
      ins[i] += bps;
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int cur_len, int i, const uint8_t * data, int counts[17],
    uint8_t lens[644], int elems)
{
  int max_bits = 0;
  int nb = 0;
  IACA_START for (i = 0; i < elems; i++)
    {
      cur_len = (nb ? *data & 0xF : *data >> 4) + 1;
      counts[cur_len]++;
      max_bits = ((max_bits) > (cur_len) ? (max_bits) : (cur_len));
      lens[i] = cur_len;
      data += nb;
      nb ^= 1;
     } IACA_END
}

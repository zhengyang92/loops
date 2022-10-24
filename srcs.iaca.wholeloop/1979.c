#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, uint8_t * yo_indices, int x, uint8_t yo1, uint8_t * dst,
    uint8_t yo0)
{
  IACA_START for (x = 0; x < 4; x++)
    {
      int yo_code = yo_indices[x + y * 4];
      dst[x] = extract_component (yo0, yo1, yo_code);
}IACA_END}

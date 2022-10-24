#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, uint8_t cg1, uint8_t co_indices[16], int x, uint8_t cg_indices[16],
    uint8_t * plane1, uint8_t * plane0, uint8_t co1, uint8_t co0, uint8_t cg0)
{
  IACA_START for (x = 0; x < 4; x++)
    {
      int co_code = co_indices[x + y * 4];
      int cg_code = cg_indices[x + y * 4];
      plane0[x] = extract_component (cg0, cg1, cg_code);
      plane1[x] = extract_component (co0, co1, co_code);
}IACA_END}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int mb_x, uint16_t (*buffer)[4], unsigned int width, uint8_t * ptr)
{
  IACA_START for (mb_x = 0; mb_x < width; mb_x++)
    {
      ((uint16_t *) ptr)[2 * mb_x + 0] = buffer[mb_x][0];
      ((uint16_t *) ptr)[2 * mb_x + 1] = buffer[mb_x][1];
     } IACA_END
}

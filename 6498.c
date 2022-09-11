#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int col, uint8_t * v_out, unsigned char *encoded, unsigned int width,
    uint8_t * y_out, uint8_t * u_out)
{
  for (col = 0; col < width - 3; col += 4)
    {
      memcpy (y_out + col, encoded, 4);
      encoded += 4;
      u_out[col >> 1] = *encoded++ + 128;
      u_out[(col >> 1) + 1] = *encoded++ + 128;
      v_out[col >> 1] = *encoded++ + 128;
      v_out[(col >> 1) + 1] = *encoded++ + 128;
    }
}

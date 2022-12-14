#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * in_buf, int x, unsigned int width, unsigned int depth,
    unsigned int bytes_per_channel, uint8_t * encode_buf, unsigned int put_be)
{
  for (x = 0; x < width * bytes_per_channel; x += bytes_per_channel)
    if (bytes_per_channel == 1)
      {
	encode_buf[x] = in_buf[depth * x];
      }
    else if (0 ^ put_be)
      {
	encode_buf[x + 1] = in_buf[depth * x];
	encode_buf[x] = in_buf[depth * x + 1];
      }
    else
      {
	encode_buf[x] = in_buf[depth * x];
	encode_buf[x + 1] = in_buf[depth * x + 1];
      }
}

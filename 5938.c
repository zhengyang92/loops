#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * pixels, int x, uint8_t * c_ptr1, uint8_t * ptr1,
    uint8_t * c_ptr)
{
  const int log2_blocksize = 3;
  for (x = 0; x < (1 << (log2_blocksize - 1)); x++)
    {
      c_ptr[x] = pixels[x];
      c_ptr1[x] = ptr1[x];
    }
}

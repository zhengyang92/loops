#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint64_t uint64_t;

int
fn (uint64_t * counts, int i, int width, uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      counts[src[i]]++;
    }
}

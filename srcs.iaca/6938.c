#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef struct HuffEntry
{
  uint16_t sym;
  uint8_t len;
  uint32_t code;
} HuffEntry;

int
fn (const uint8_t * src, HuffEntry he[1024], int i)
{
  for (i = 0; i < 1024; i++)
    {
      he[i].sym = i;
      he[i].len = *src++;
    }
}

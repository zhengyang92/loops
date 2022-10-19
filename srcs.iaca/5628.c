#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * buf, int len, int frames)
{
  for (frames = 1; frames < len && (buf[frames] & 0x80); frames++);
}

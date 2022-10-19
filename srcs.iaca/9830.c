#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char uint8;
typedef unsigned int uint32;
typedef signed long tmsize_t;

int
fn (uint32 bps, tmsize_t wc, uint32 byte, uint8 * cp, uint8 * tmp,
    tmsize_t count)
{
  for (byte = 0; byte < bps; byte++)
    {
      cp[bps * count + byte] = tmp[(bps - byte - 1) * wc + count];
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct GetBitContext
{
  const uint8_t *buffer, *buffer_end;
  int index;
  int size_in_bits;
  int size_in_bits_plus8;
} GetBitContext;
typedef struct RawBitsContext
{
  const uint8_t *position;
  uint32_t bytes;
  uint32_t cachelen;
  uint32_t cacheval;
} RawBitsContext;
typedef OpusRangeCoder;
typedef __int32_t int32_t;

int
fn (int d, OpusRangeCoder * rc, int32_t branch[4][2], int32_t * location)
{
  for (d = 0; d < 2; d++)
    {
      silk_count_children (rc, 3, branch[3][d], location);
      location += 2;
    }
}

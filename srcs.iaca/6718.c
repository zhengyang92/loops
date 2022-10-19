#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct BitstreamContext
{
  uint64_t bits;
  const uint8_t *buffer, *buffer_end;
  const uint8_t *ptr;
  unsigned bits_left;
  unsigned size_in_bits;
} BitstreamContext;
typedef struct RawBitsContext
{
  const uint8_t *position;
  unsigned int bytes;
  unsigned int cachelen;
  unsigned int cacheval;
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

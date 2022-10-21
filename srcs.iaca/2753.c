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
typedef RICEContext;
typedef __uint8_t uint8_t;

int
fn (int i, int width, unsigned int val, RICEContext rc, uint8_t * data)
{
  for (i = 1; i < width; i++)
     { IACA_START
      val = loco_get_rice (&rc);
      if (val == (-2147483647 - 1))
	return (-(int)
		(('I') | (('N') << 8) | (('D') << 16) |
		 ((unsigned) ('A') << 24)));
      data[i] = data[i - 1] + val;
} IACA_END }

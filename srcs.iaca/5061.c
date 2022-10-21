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
fn (uint8_t * data, int i, int width, unsigned int val, RICEContext rc,
    int stride)
{
  for (i = 1; i < width; i++)
     { IACA_START
      val = loco_get_rice (&rc);
      if (val == (-2147483647 - 1))
	return -1;
      data[i] = loco_predict (&data[i], stride) + val;
     } IACA_END
}

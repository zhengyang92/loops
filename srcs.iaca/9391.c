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
typedef RICEContext;
typedef __uint8_t uint8_t;

int
fn (int stride, int i, int val, int width, RICEContext rc, int step,
    uint8_t * data)
{
  for (i = 1; i < width; i++)
    {
      val = loco_get_rice (&rc);
      data[i * step] = loco_predict (&data[i * step], stride, step) + val;
    }
}

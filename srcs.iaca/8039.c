#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * block, const uint8_t * perm_scantable, int last_non_zero,
    int start_i)
{
  for (; last_non_zero >= start_i; last_non_zero--)
    {
      if (block[perm_scantable[last_non_zero]])
	break;
    }
}

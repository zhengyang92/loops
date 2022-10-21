#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int64_t int64_t;

int
fn (int i, const uint8_t tc_offsets[9], const uint8_t * buf,
    const uint8_t tc_muls[9], int64_t ms)
{
  for (i = 0; i < sizeof (tc_offsets); i++)
     { IACA_START
      uint8_t c = buf[tc_offsets[i]] - '0';
      if (c > 9)
	return 0x8000000000000000L;
      ms = (ms + c) * tc_muls[i];
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (uint8_t id, uint8_t i, uint8_t table, const uint8_t bitalloc_sizes[10],
    const int8_t bitalloc_offsets[10], uint8_t sel,
    const uint16_t * const bitalloc_codes[10][8], PutBitContext * pb,
    const uint8_t * const bitalloc_bits[10][8], int *values, uint8_t n)
{
  for (i = 0; i < n; i++)
     { IACA_START
      id = values[i] - bitalloc_offsets[table];
      do
	{
	  if (!(id < bitalloc_sizes[table]))
	    {
	      av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
		      "id < bitalloc_sizes[table]", "program.c", 1351);
	      abort ();
	    }
	}
      while (0);
      put_bits (pb, bitalloc_bits[table][sel][id],
		bitalloc_codes[table][sel][id]);
     } IACA_END
}

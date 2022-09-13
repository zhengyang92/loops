#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;
typedef __int8_t int8_t;

int
fn (uint32_t sum, uint8_t id, uint8_t i, uint8_t table,
    const uint8_t bitalloc_sizes[10], const int8_t bitalloc_offsets[10],
    uint8_t sel, const uint8_t * const bitalloc_bits[10][8], int *values,
    uint8_t n)
{
  for (i = 0; i < n; i++)
    {
      id = values[i] - bitalloc_offsets[table];
      do
	{
	  if (!(id < bitalloc_sizes[table]))
	    {
	      av_log (((void *) 0), 0, "Assertion %s failed at %s:%d\n",
		      "id < bitalloc_sizes[table]", "program.c", 1340);
	      abort ();
	    }
	}
      while (0);
      sum += bitalloc_bits[table][sel][id];
    }
}

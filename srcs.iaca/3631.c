#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t term_bits[22], uint32_t local_best_bits, int best_term)
{
  int i = 0;
  for (i = 0; i < 22; i++) {
	  IACA_START
    if (term_bits[i] && term_bits[i] < local_best_bits)
      {
	local_best_bits = term_bits[i];
	best_term = i - 3;
      }
  }
  IACA_END
}

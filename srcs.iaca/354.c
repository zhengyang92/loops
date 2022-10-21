#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (double *relative_threshold, size_t j, double histogram_energies[1000],
    unsigned long *block_energy_histogram)
{
  int above_thresh_counter = 0;
  for (j = 0; j < 1000; ++j)
     { IACA_START
      *relative_threshold +=
	block_energy_histogram[j] * histogram_energies[j];
      above_thresh_counter += block_energy_histogram[j];
     } IACA_END
}

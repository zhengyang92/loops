#include <stdint.h>
#include <stdio.h>






int
fn (int pulse_idx, int pulse,
    const uint32_t dss_sp_combinatorial_table[8][72],
    unsigned int combined_pulse_pos)
{
  for (; combined_pulse_pos < dss_sp_combinatorial_table[pulse][pulse_idx];
       --pulse_idx);
}

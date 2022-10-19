#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (unsigned int entries, unsigned int ce, uint8_t * tmp_vlc_bits,
    unsigned int used_entries, unsigned int flag, GetBitContext * gb)
{
  for (ce = 0; ce < entries; ++ce)
    {
      flag = get_bits1 (gb);
      if (flag)
	{
	  tmp_vlc_bits[ce] = get_bits (gb, 5) + 1;
	  ++used_entries;
	}
      else
	tmp_vlc_bits[ce] = 0;
    }
}

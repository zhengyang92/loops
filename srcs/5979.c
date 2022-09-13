#include <stdint.h>
#include <stdio.h>




typedef struct VLC
{
  int bits;
    int16_t (*table)[];
  int table_size, table_allocated;
} VLC;
typedef __uint16_t uint16_t;

int
fn (int i, const uint8_t ccitt_codes_bits[2][104],
    const uint16_t ccitt_syms[104], const uint8_t ccitt_codes_lens[2][104],
    VLC ccitt_vlc[2])
{
  for (i = 0; i < 2; i++)
    {
      ff_init_vlc_sparse (&ccitt_vlc[i], 9, 104, ccitt_codes_lens[i], 1, 1,
			  ccitt_codes_bits[i], 1, 1, ccitt_syms, 2, 2, 4);
    }
}

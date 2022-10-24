#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct VLC
{
  int bits;
    int16_t (*table)[];
  int table_size, table_allocated;
} VLC;

int
fn (const uint8_t mpa_quad_codes[2][16], VLC ff_huff_quad_vlc[2], int offset,
    const uint8_t mpa_quad_bits[2][16], int16_t huff_quad_vlc_tables[80][2])
{
  IACA_START for (int i = 0; i < 2; i++)
    {
      int bits = i == 0 ? 6 : 4;
      ff_huff_quad_vlc[i].table = huff_quad_vlc_tables + offset;
      ff_huff_quad_vlc[i].table_allocated = 1 << bits;
      offset += 1 << bits;
      ff_init_vlc_sparse (&ff_huff_quad_vlc[i], bits, 16, mpa_quad_bits[i], 1,
			  1, mpa_quad_codes[i], 1, 1, ((void *) 0), 0, 0, 4);
}IACA_END}

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
fn (const uint8_t mpa_quad_codes[2][16], VLC huff_quad_vlc[2], int offset,
    int i, const int huff_quad_vlc_tables_sizes[2],
    int16_t huff_quad_vlc_tables[144][2], const uint8_t mpa_quad_bits[2][16])
{
  IACA_START for (i = 0; i < 2; i++)
    {
      huff_quad_vlc[i].table = huff_quad_vlc_tables + offset;
      huff_quad_vlc[i].table_allocated = huff_quad_vlc_tables_sizes[i];
      ff_init_vlc_sparse (&huff_quad_vlc[i], i == 0 ? 7 : 4, 16,
			  mpa_quad_bits[i], 1, 1, mpa_quad_codes[i], 1, 1,
			  ((void *) 0), 0, 0, 4);
      offset += huff_quad_vlc_tables_sizes[i];
}IACA_END}

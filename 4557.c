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
fn (int16_t vlc_buf[3958][2],
    const uint16_t * const ff_aac_spectral_codes[11], VLC vlc_spectral[11],
    const uint16_t * const ff_aac_codebook_vector_idx[],
    const uint16_t ff_aac_spectral_sizes[11],
    const uint8_t * const ff_aac_spectral_bits[11])
{
  for (unsigned i = 0, offset = 0; i < 11; i++)
    {
      vlc_spectral[i].table = &vlc_buf[offset];
      vlc_spectral[i].table_allocated =
	(sizeof (vlc_buf) / sizeof ((vlc_buf)[0])) - offset;
      ff_init_vlc_sparse (&vlc_spectral[i], 8, ff_aac_spectral_sizes[i],
			  ff_aac_spectral_bits[i],
			  sizeof (ff_aac_spectral_bits[i][0]),
			  sizeof (ff_aac_spectral_bits[i][0]),
			  ff_aac_spectral_codes[i],
			  sizeof (ff_aac_spectral_codes[i][0]),
			  sizeof (ff_aac_spectral_codes[i][0]),
			  ff_aac_codebook_vector_idx[i],
			  sizeof (ff_aac_codebook_vector_idx[i][0]),
			  sizeof (ff_aac_codebook_vector_idx[i][0]), (1 | 4));
      offset += vlc_spectral[i].table_size;
    }
}

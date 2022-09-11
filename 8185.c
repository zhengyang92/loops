#include <stdint.h>
#include <stdio.h>




typedef struct vorbis_floor0_s
{
  uint8_t order;
  uint16_t rate;
  uint16_t bark_map_size;
  int32_t *map[2];
  uint32_t map_size[2];
  uint8_t amplitude_bits;
  uint8_t amplitude_offset;
  uint8_t num_books;
  uint8_t *book_list;
  float *lsp;
} vorbis_floor0_s;
typedef struct vorbis_floor0_s vorbis_floor0;
typedef __int32_t int32_t;

int
fn (int idx, int32_t * map, vorbis_floor0 * vf, int n)
{
  for (idx = 0; idx < n; ++idx)
    {
      map[idx] =
	floor ((13.1f * atan (0.00074f * ((vf->rate * idx) / (2.0f * n))) +
		2.24f * atan (1.85e-8f * ((vf->rate * idx) / (2.0f * n)) *
			      ((vf->rate * idx) / (2.0f * n))) +
		1e-4f * ((vf->rate * idx) / (2.0f * n))) *
	       (vf->bark_map_size /
		(13.1f * atan (0.00074f * (vf->rate / 2.0f)) +
		 2.24f * atan (1.85e-8f * (vf->rate / 2.0f) *
			       (vf->rate / 2.0f)) +
		 1e-4f * (vf->rate / 2.0f))));
      if (vf->bark_map_size - 1 < map[idx])
	map[idx] = vf->bark_map_size - 1;
    }
}

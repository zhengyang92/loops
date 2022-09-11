#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int exact, int bits, const int max_quantization, int used_subtract_green,
    uint32_t * const argb, int tile_x, int width, int histo[4][256],
    const int tiles_per_row, int tile_y, uint32_t * const image,
    uint32_t * const argb_scratch, int height)
{
  for (tile_x = 0; tile_x < tiles_per_row; ++tile_x)
    {
      const int pred =
	GetBestPredictorForTile (width, height, tile_x, tile_y, bits, histo,
				 argb_scratch, argb, max_quantization, exact,
				 used_subtract_green, image);
      image[tile_y * tiles_per_row + tile_x] = 0xff000000 | (pred << 8);
}}

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const int uv_width, int do_store, uint8_t * v, int i, int YUV_HALF,
    const uint32_t * argb, uint8_t * u)
{
  for (i = 0; i < uv_width; ++i)
    {
      const uint32_t v0 = argb[2 * i + 0];
      const uint32_t v1 = argb[2 * i + 1];
      const int r = ((v0 >> 15) & 0x1fe) + ((v1 >> 15) & 0x1fe);
      const int g = ((v0 >> 7) & 0x1fe) + ((v1 >> 7) & 0x1fe);
      const int b = ((v0 << 1) & 0x1fe) + ((v1 << 1) & 0x1fe);
      const int tmp_u = VP8RGBToU (r, g, b, YUV_HALF << 2);
      const int tmp_v = VP8RGBToV (r, g, b, YUV_HALF << 2);
      if (do_store)
	{
	  u[i] = tmp_u;
	  v[i] = tmp_v;
	}
      else
	{
	  u[i] = (u[i] + tmp_u + 1) >> 1;
	  v[i] = (v[i] + tmp_v + 1) >> 1;
	}
    }
}

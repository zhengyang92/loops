#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int w, const int rnd, const uint8_t * yuv2, int crv, int cgu, int cgv,
    int cy, const ptrdiff_t *yuv_stride, const int16_t * yuv_offset, int x,
    int16_t * rgb1, const int sh, const uint8_t * yuv1, const uint8_t * yuv0,
    int cbu, const int uv_offset, ptrdiff_t rgb_stride, int16_t * rgb2,
    int16_t * rgb0)
{
  for (x = 0; x < w; x++)
    {
      int y00 = yuv0[x << 1] - yuv_offset[0];
      int y01 = yuv0[2 * x + 1] - yuv_offset[0];
      int y10 =
	yuv0[yuv_stride[0] / sizeof (uint8_t) + 2 * x] - yuv_offset[0];
      int y11 =
	yuv0[yuv_stride[0] / sizeof (uint8_t) + 2 * x + 1] - yuv_offset[0];
      int u = yuv1[x] - uv_offset, v = yuv2[x] - uv_offset;
      rgb0[x << 1] = av_clip_int16_c ((y00 * cy + crv * v + rnd) >> sh);
      rgb0[2 * x + 1] = av_clip_int16_c ((y01 * cy + crv * v + rnd) >> sh);
      rgb0[2 * x + rgb_stride] =
	av_clip_int16_c ((y10 * cy + crv * v + rnd) >> sh);
      rgb0[2 * x + rgb_stride + 1] =
	av_clip_int16_c ((y11 * cy + crv * v + rnd) >> sh);
      rgb1[x << 1] =
	av_clip_int16_c ((y00 * cy + cgu * u + cgv * v + rnd) >> sh);
      rgb1[2 * x + 1] =
	av_clip_int16_c ((y01 * cy + cgu * u + cgv * v + rnd) >> sh);
      rgb1[2 * x + rgb_stride] =
	av_clip_int16_c ((y10 * cy + cgu * u + cgv * v + rnd) >> sh);
      rgb1[2 * x + rgb_stride + 1] =
	av_clip_int16_c ((y11 * cy + cgu * u + cgv * v + rnd) >> sh);
      rgb2[x << 1] = av_clip_int16_c ((y00 * cy + cbu * u + rnd) >> sh);
      rgb2[2 * x + 1] = av_clip_int16_c ((y01 * cy + cbu * u + rnd) >> sh);
      rgb2[2 * x + rgb_stride] =
	av_clip_int16_c ((y10 * cy + cbu * u + rnd) >> sh);
      rgb2[2 * x + rgb_stride + 1] =
	av_clip_int16_c ((y11 * cy + cbu * u + rnd) >> sh);
}}

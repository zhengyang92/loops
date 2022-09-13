#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int cvv, int w, int cyv, const int rnd, int y_off_in, int cyu,
    uint8_t * dst0, uint8_t * dst2, int cuv, int y_off_out, int x,
    const int sh, const uint8_t * src1, int cuu, int cvu, const int uv_off_in,
    const uint8_t * src2, uint8_t * dst1, const int uv_off_out,
    const uint8_t * src0, int cyy)
{
  for (x = 0; x < w; x++)
    {
      int y00 = src0[x << 1] - y_off_in;
      int y01 = src0[2 * x + 1] - y_off_in;
      int u = src1[x] - uv_off_in, v = src2[x] - uv_off_in;
      int uv_val = cyu * u + cyv * v + rnd + y_off_out;
      dst0[x << 1] = av_clip_uint8_c ((cyy * y00 + uv_val) >> sh);
      dst0[x * 2 + 1] = av_clip_uint8_c ((cyy * y01 + uv_val) >> sh);
      dst1[x] = av_clip_uint8_c ((u * cuu + v * cuv + uv_off_out) >> sh);
      dst2[x] = av_clip_uint8_c ((u * cvu + v * cvv + uv_off_out) >> sh);
}}
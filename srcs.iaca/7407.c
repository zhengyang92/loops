#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int cvv, int w, int cyv, const int rnd, int y_off_in, int cyu,
    uint8_t * dst0, uint8_t * dst2, int cuv, int y_off_out, int x,
    const int sh, const uint8_t * src1, const ptrdiff_t *src_stride, int cuu,
    const ptrdiff_t *dst_stride, int cvu, const int uv_off_in,
    const uint8_t * src2, uint8_t * dst1, const int uv_off_out,
    const uint8_t * src0, int cyy)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int y00 = src0[x << 1] - y_off_in;
      int y01 = src0[2 * x + 1] - y_off_in;
      int y10 = src0[src_stride[0] / sizeof (uint8_t) + 2 * x] - y_off_in;
      int y11 = src0[src_stride[0] / sizeof (uint8_t) + 2 * x + 1] - y_off_in;
      int u = src1[x] - uv_off_in, v = src2[x] - uv_off_in;
      int uv_val = cyu * u + cyv * v + rnd + y_off_out;
      dst0[x << 1] = av_clip_uint8_c ((cyy * y00 + uv_val) >> sh);
      dst0[x * 2 + 1] = av_clip_uint8_c ((cyy * y01 + uv_val) >> sh);
      dst0[x * 2 + 0 + dst_stride[0] / sizeof (uint8_t)] =
	av_clip_uint8_c ((cyy * y10 + uv_val) >> sh);
      dst0[x * 2 + 1 + dst_stride[0] / sizeof (uint8_t)] =
	av_clip_uint8_c ((cyy * y11 + uv_val) >> sh);
      dst1[x] = av_clip_uint8_c ((u * cuu + v * cuv + uv_off_out) >> sh);
      dst2[x] = av_clip_uint8_c ((u * cvu + v * cvv + uv_off_out) >> sh);
     } IACA_END
}

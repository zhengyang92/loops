#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (stbi_uc * o, int i, int val[64], int *v, int out_stride, stbi_uc * out)
{
  IACA_START for (i = 0, v = val, o = out; i < 8; ++i, v += 8, o += out_stride)
    {
      int t0, t1, t2, t3, p1, p2, p3, p4, p5, x0, x1, x2, x3;
      p2 = v[2];
      p3 = v[6];
      p1 = (p2 + p3) * ((int) (((0.5411961f) * 4096 + 0.5)));
      t2 = p1 + p3 * ((int) (((-1.847759065f) * 4096 + 0.5)));
      t3 = p1 + p2 * ((int) (((0.765366865f) * 4096 + 0.5)));
      p2 = v[0];
      p3 = v[4];
      t0 = ((p2 + p3) * 4096);
      t1 = ((p2 - p3) * 4096);
      x0 = t0 + t3;
      x3 = t0 - t3;
      x1 = t1 + t2;
      x2 = t1 - t2;
      t0 = v[7];
      t1 = v[5];
      t2 = v[3];
      t3 = v[1];
      p3 = t0 + t2;
      p4 = t1 + t3;
      p1 = t0 + t3;
      p2 = t1 + t2;
      p5 = (p3 + p4) * ((int) (((1.175875602f) * 4096 + 0.5)));
      t0 = t0 * ((int) (((0.298631336f) * 4096 + 0.5)));
      t1 = t1 * ((int) (((2.053119869f) * 4096 + 0.5)));
      t2 = t2 * ((int) (((3.072711026f) * 4096 + 0.5)));
      t3 = t3 * ((int) (((1.501321110f) * 4096 + 0.5)));
      p1 = p5 + p1 * ((int) (((-0.899976223f) * 4096 + 0.5)));
      p2 = p5 + p2 * ((int) (((-2.562915447f) * 4096 + 0.5)));
      p3 = p3 * ((int) (((-1.961570560f) * 4096 + 0.5)));
      p4 = p4 * ((int) (((-0.390180644f) * 4096 + 0.5)));
      t3 += p1 + p4;
      t2 += p2 + p3;
      t1 += p2 + p4;
      t0 += p1 + p3;
      x0 += 65536 + (128 << 17);
      x1 += 65536 + (128 << 17);
      x2 += 65536 + (128 << 17);
      x3 += 65536 + (128 << 17);
      o[0] = stbi__clamp ((x0 + t3) >> 17);
      o[7] = stbi__clamp ((x0 - t3) >> 17);
      o[1] = stbi__clamp ((x1 + t2) >> 17);
      o[6] = stbi__clamp ((x1 - t2) >> 17);
      o[2] = stbi__clamp ((x2 + t1) >> 17);
      o[5] = stbi__clamp ((x2 - t1) >> 17);
      o[3] = stbi__clamp ((x3 + t0) >> 17);
      o[4] = stbi__clamp ((x3 - t0) >> 17);
}IACA_END}

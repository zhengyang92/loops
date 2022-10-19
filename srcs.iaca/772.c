#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int src_stridea, int i, int dst_strideb, float *dst,
    int src_strideb, int dst_stridea)
{
  for (i = 0; i < 16; i++)
    {
      const float x00 = src[0 * src_stridea] + src[15 * src_stridea];
      const float x01 = src[1 * src_stridea] + src[14 * src_stridea];
      const float x02 = src[2 * src_stridea] + src[13 * src_stridea];
      const float x03 = src[3 * src_stridea] + src[12 * src_stridea];
      const float x04 = src[4 * src_stridea] + src[11 * src_stridea];
      const float x05 = src[5 * src_stridea] + src[10 * src_stridea];
      const float x06 = src[6 * src_stridea] + src[9 * src_stridea];
      const float x07 = src[7 * src_stridea] + src[8 * src_stridea];
      const float x08 = src[0 * src_stridea] - src[15 * src_stridea];
      const float x09 = src[1 * src_stridea] - src[14 * src_stridea];
      const float x0a = src[2 * src_stridea] - src[13 * src_stridea];
      const float x0b = src[3 * src_stridea] - src[12 * src_stridea];
      const float x0c = src[4 * src_stridea] - src[11 * src_stridea];
      const float x0d = src[5 * src_stridea] - src[10 * src_stridea];
      const float x0e = src[6 * src_stridea] - src[9 * src_stridea];
      const float x0f = src[7 * src_stridea] - src[8 * src_stridea];
      const float x10 = x00 + x07;
      const float x11 = x01 + x06;
      const float x12 = x02 + x05;
      const float x13 = x03 + x04;
      const float x14 = x00 - x07;
      const float x15 = x01 - x06;
      const float x16 = x02 - x05;
      const float x17 = x03 - x04;
      const float x18 = x10 + x13;
      const float x19 = x11 + x12;
      const float x1a = x10 - x13;
      const float x1b = x11 - x12;
      const float x1c = 1.38703984532215f * x14 + 0.275899379282943f * x17;
      const float x1d = 1.17587560241936f * x15 + 0.785694958387102f * x16;
      const float x1e = -0.785694958387102f * x15 + 1.17587560241936f * x16;
      const float x1f = 0.275899379282943f * x14 - 1.38703984532215f * x17;
      const float x20 = 0.25f * (x1c - x1d);
      const float x21 = 0.25f * (x1e - x1f);
      const float x22 = 1.40740373752638f * x08 + 0.138617169199091f * x0f;
      const float x23 = 1.35331800117435f * x09 + 0.410524527522357f * x0e;
      const float x24 = 1.24722501298667f * x0a + 0.666655658477747f * x0d;
      const float x25 = 1.09320186700176f * x0b + 0.897167586342636f * x0c;
      const float x26 = -0.897167586342636f * x0b + 1.09320186700176f * x0c;
      const float x27 = 0.666655658477747f * x0a - 1.24722501298667f * x0d;
      const float x28 = -0.410524527522357f * x09 + 1.35331800117435f * x0e;
      const float x29 = 0.138617169199091f * x08 - 1.40740373752638f * x0f;
      const float x2a = x22 + x25;
      const float x2b = x23 + x24;
      const float x2c = x22 - x25;
      const float x2d = x23 - x24;
      const float x2e = 0.25f * (x2a - x2b);
      const float x2f = 0.326640741219094f * x2c + 0.135299025036549f * x2d;
      const float x30 = 0.135299025036549f * x2c - 0.326640741219094f * x2d;
      const float x31 = x26 + x29;
      const float x32 = x27 + x28;
      const float x33 = x26 - x29;
      const float x34 = x27 - x28;
      const float x35 = 0.25f * (x31 - x32);
      const float x36 = 0.326640741219094f * x33 + 0.135299025036549f * x34;
      const float x37 = 0.135299025036549f * x33 - 0.326640741219094f * x34;
      dst[0 * dst_stridea] = 0.25f * (x18 + x19);
      dst[1 * dst_stridea] = 0.25f * (x2a + x2b);
      dst[2 * dst_stridea] = 0.25f * (x1c + x1d);
      dst[3 * dst_stridea] = 0.707106781186547f * (x2f - x37);
      dst[4 * dst_stridea] =
	0.326640741219094f * x1a + 0.135299025036549f * x1b;
      dst[5 * dst_stridea] = 0.707106781186547f * (x2f + x37);
      dst[6 * dst_stridea] = 0.707106781186547f * (x20 - x21);
      dst[7 * dst_stridea] = 0.707106781186547f * (x2e + x35);
      dst[8 * dst_stridea] = 0.25f * (x18 - x19);
      dst[9 * dst_stridea] = 0.707106781186547f * (x2e - x35);
      dst[10 * dst_stridea] = 0.707106781186547f * (x20 + x21);
      dst[11 * dst_stridea] = 0.707106781186547f * (x30 - x36);
      dst[12 * dst_stridea] =
	0.135299025036549f * x1a - 0.326640741219094f * x1b;
      dst[13 * dst_stridea] = 0.707106781186547f * (x30 + x36);
      dst[14 * dst_stridea] = 0.25f * (x1e + x1f);
      dst[15 * dst_stridea] = 0.25f * (x31 + x32);
      dst += dst_strideb;
      src += src_strideb;
}}

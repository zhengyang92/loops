#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int dst_stride, int i, int width, const uint8_t * src, int src_stride,
    uint16_t * dst)
{
  for (i = 2; i < width - 2; i += 2)
    {
      dst[(0) * dst_stride + (0) * 3 + 0] =
	((unsigned int) (src[(-1) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (0)])) >> 1;
      dst[(0) * dst_stride + (0) * 3 + 1] = (src[(0) * src_stride + 1 * (0)]);
      dst[(0) * dst_stride + (0) * 3 + 2] =
	((unsigned int) (src[(0) * src_stride + 1 * (-1)]) +
	 (unsigned int) (src[(0) * src_stride + 1 * (1)])) >> 1;
      dst[(0) * dst_stride + (1) * 3 + 0] =
	((unsigned int) (src[(-1) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(-1) * src_stride + 1 * (2)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (2)])) >> 2;
      dst[(0) * dst_stride + (1) * 3 + 1] =
	((unsigned int) (src[(-1) * src_stride + 1 * (1)]) +
	 (unsigned int) (src[(0) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(0) * src_stride + 1 * (2)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (1)])) >> 2;
      dst[(0) * dst_stride + (1) * 3 + 2] = (src[(0) * src_stride + 1 * (1)]);
      dst[(1) * dst_stride + (0) * 3 + 0] = (src[(1) * src_stride + 1 * (0)]);
      dst[(1) * dst_stride + (0) * 3 + 1] =
	((unsigned int) (src[(0) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (-1)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (1)]) +
	 (unsigned int) (src[(2) * src_stride + 1 * (0)])) >> 2;
      dst[(1) * dst_stride + (0) * 3 + 2] =
	((unsigned int) (src[(0) * src_stride + 1 * (-1)]) +
	 (unsigned int) (src[(0) * src_stride + 1 * (1)]) +
	 (unsigned int) (src[(2) * src_stride + 1 * (-1)]) +
	 (unsigned int) (src[(2) * src_stride + 1 * (1)])) >> 2;
      dst[(1) * dst_stride + (1) * 3 + 0] =
	((unsigned int) (src[(1) * src_stride + 1 * (0)]) +
	 (unsigned int) (src[(1) * src_stride + 1 * (2)])) >> 1;
      dst[(1) * dst_stride + (1) * 3 + 1] = (src[(1) * src_stride + 1 * (1)]);
      dst[(1) * dst_stride + (1) * 3 + 2] =
	((unsigned int) (src[(0) * src_stride + 1 * (1)]) +
	 (unsigned int) (src[(2) * src_stride + 1 * (1)])) >> 1;
      src += 2 * 1;
      dst += 6;
}}

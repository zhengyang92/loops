#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct color_ref
{
  uint32_t color;
  uint64_t count;
} color_ref;
typedef struct range_box
{
  uint32_t color;
  int64_t variance;
  int start;
  int len;
  int sorted_by;
} range_box;
typedef __uint64_t uint64_t;

int
fn (int use_alpha, int i, uint64_t a, uint64_t r, uint64_t b, const int n,
    const struct range_box *box, struct color_ref *const *refs, uint64_t g,
    uint64_t div)
{
  for (i = 0; i < n; i++)
    {
      const struct color_ref *ref = refs[box->start + i];
      if (use_alpha)
	a += (ref->color >> 24 & 0xff) * ref->count;
      r += (ref->color >> 16 & 0xff) * ref->count;
      g += (ref->color >> 8 & 0xff) * ref->count;
      b += (ref->color & 0xff) * ref->count;
      div += ref->count;
    }
}

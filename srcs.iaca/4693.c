#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __int32_t int32_t;

int
fn (int32_t * dst, int i, int32_t prev, ptrdiff_t len, const int32_t * src)
{
  for (i = 0; i < len; i++)
    {
      int64_t a = 2097471L * src[i] + 6291137L * prev;
      int64_t b = 6291137L * src[i] + 2097471L * prev;
      prev = src[i];
      *dst++ = clip23 (norm23 (a));
      *dst++ = clip23 (norm23 (b));
    }
}

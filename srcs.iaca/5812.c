#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * dsti, int i, uint32_t maxisign, uint32_t mini, int len,
    const uint32_t * srci, uint32_t maxi)
{
  for (i = 0; i < len; i += 8)
    {
      dsti[i + 0] = clipf_c_one (srci[i + 0], mini, maxi, maxisign);
      dsti[i + 1] = clipf_c_one (srci[i + 1], mini, maxi, maxisign);
      dsti[i + 2] = clipf_c_one (srci[i + 2], mini, maxi, maxisign);
      dsti[i + 3] = clipf_c_one (srci[i + 3], mini, maxi, maxisign);
      dsti[i + 4] = clipf_c_one (srci[i + 4], mini, maxi, maxisign);
      dsti[i + 5] = clipf_c_one (srci[i + 5], mini, maxi, maxisign);
      dsti[i + 6] = clipf_c_one (srci[i + 6], mini, maxi, maxisign);
      dsti[i + 7] = clipf_c_one (srci[i + 7], mini, maxi, maxisign);
    }
}

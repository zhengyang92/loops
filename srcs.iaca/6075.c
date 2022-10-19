#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *rrp, int i, int *v, int in)
{
  for (i = 7; i >= 0; i--)
    {
      in -= gsm_mult (rrp[i], v[i]);
      v[i + 1] = v[i] + gsm_mult (rrp[i], in);
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef image;
typedef unsigned long int pthread_t;

int
fn (int m, image * val, image * buf, int t, image * val_resized,
    image * buf_resized, pthread_t * thr)
{
  int i = 0;
  int nthreads = 4;
  for (t = 0; t < nthreads && i + t - nthreads < m; ++t)
    {
      pthread_join (thr[t], 0);
      val[t] = buf[t];
      val_resized[t] = buf_resized[t];
    }
}

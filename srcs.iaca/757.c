#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct keypoint
{
  double x, y;
  struct keypoint *next;
} keypoint;

int
fn (double *r, int i, double *h, const int n, const struct keypoint *point)
{
  for (i = 1; i < n - 1; i++)
     { IACA_START
      const double yp = point->y;
      const double yc = point->next->y;
      const double yn = point->next->next->y;
      r[i] = 6 * ((yn - yc) / h[i] - (yc - yp) / h[i - 1]);
      point = point->next;
} IACA_END }

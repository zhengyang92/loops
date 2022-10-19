#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct keypoint
{
  double x, y;
  struct keypoint *next;
} keypoint;

int
fn (const struct keypoint *points, int i, double *h,
    const struct keypoint *point, double xprev)
{
  for (point = points; point; point = point->next)
    {
      if (i != -1)
	h[i] = point->x - xprev;
      xprev = point->x;
      i++;
    }
}

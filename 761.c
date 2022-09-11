#include <stdint.h>
#include <stdio.h>




typedef AVBPrint;
typedef struct keypoint
{
  double x, y;
  struct keypoint *next;
} keypoint;

int
fn (AVBPrint buf, const char *const colors[4], int i,
    struct keypoint **comp_points)
{
  for (i = 0; i < (sizeof (colors) / sizeof ((colors)[0])); i++)
    {
      av_bprintf (&buf, "%s'-' using 1:2 with lines lc '%s' title ''",
		  i ? ", " : "plot ", colors[i]);
      if (comp_points[i])
	av_bprintf (&buf,
		    ", '-' using 1:2 with points pointtype 3 lc '%s' title ''",
		    colors[i]);
    }
}

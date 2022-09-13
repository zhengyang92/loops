#include <stdint.h>
#include <stdio.h>






int
fn (const float *v_list, int i, float v, int v_list_size)
{
  for (i = 0; i < v_list_size; i++)
    {
      if (v < (v_list[i] + 0.01) && v > (v_list[i] - 0.01))
	break;
    }
}

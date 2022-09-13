#include <stdint.h>
#include <stdio.h>






int
fn (int v_list_size, int i, float v, const float *v_list)
{
  for (i = 0; i < v_list_size; i++)
    {
      if (v < (v_list[i] + 0.01) && v > (v_list[i] - 0.01))
	break;
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (int *width_ptr, int i, const int sizes[9][2], int size, int *height_ptr)
{
  for (i = 0; i < (sizeof (sizes) / sizeof ((sizes)[0])); i++)
    {
      if ((sizes[i][0] * sizes[i][1]) == size)
	{
	  *width_ptr = sizes[i][0];
	  *height_ptr = sizes[i][1];
	  return 0;
	}
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (int max, int markers[64], int i, int sum)
{
  for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i++)
    {
      sum += markers[i];
      if (markers[max] < markers[i])
	max = i;
    }
}

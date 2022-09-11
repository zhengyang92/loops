#include <stdint.h>
#include <stdio.h>






int
fn (float (*in)[44][2], int i)
{
  for (i = 0; i < 5; i++)
    {
      memcpy (in[i], in[i] + 32, 6 * sizeof (in[i][0]));
    }
}

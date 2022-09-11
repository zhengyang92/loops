#include <stdint.h>
#include <stdio.h>






int
fn (int i, int b3_mantissas[8])
{
  for (i = 0; i < 7; i++)
    {
      b3_mantissas[i] = symmetric_dequant (i, 7);
    }
}

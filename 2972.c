#include <stdint.h>
#include <stdio.h>






int
fn (int i, float (*opt)[35768])
{
  for (i = 0; i < 23 * ((1 << 15) + 3000); i++)
    {
      opt[0][i] = (__builtin_inff ());
    }
}

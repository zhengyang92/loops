#include <stdint.h>
#include <stdio.h>






int
fn (int *table, int out, int in)
{
  for (; in <= 255; in++)
    {
      table[in] = out;
      table[-in] = -out;
    }
}

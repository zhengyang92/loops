#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int m, int i, char **random_paths, char **paths, int n)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      int index = rand () % m;
      random_paths[i] = paths[index];
}IACA_END}

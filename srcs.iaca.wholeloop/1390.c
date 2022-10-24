#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int e, int i, unsigned int offset_table[4])
{
  IACA_START for (e = i + 1; e < 3 && offset_table[e] == 0; e++);
  IACA_END
}

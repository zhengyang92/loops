#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int j, const char *key, const char *s)
{
  IACA_START for (j = 0; s[j] == key[j] && key[j]; j++);
  IACA_END
}

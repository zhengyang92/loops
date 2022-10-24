#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const char *str, int i)
{
  IACA_START for (++i; str[i] && str[i] != ']'; i++);
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t len, size_t i, const char *s)
{
  IACA_START for (i = 0; i < len && s[i]; i++);
}

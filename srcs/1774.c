#include <stdint.h>
#include <stdio.h>






int
fn (const char *str, int i)
{
  for (++i; str[i] && str[i] != ']'; i++);
}

#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int j, const char *key, const char *s)
{
  for (j = 0; av_toupper (s[j]) == av_toupper (key[j]) && key[j]; j++);
}

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t i, size_t offset, size_t len, char *s)
{
  for (i = 0; i < len; ++i)
    {
      char c = s[i];
      if (c == ' ' || c == '\t' || c == '\n')
	++offset;
      else
	s[i - offset] = c;
    }
}

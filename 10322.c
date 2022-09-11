#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef stbi__context;

int
fn (char *token, stbi__context * s, char buffer[1024])
{
  int valid = 0;
  for (;;)
    {
      token = stbi__hdr_gettoken (s, buffer);
      if (token[0] == 0)
	break;
      if (strcmp (token, "FORMAT=32-bit_rle_rgbe") == 0)
	valid = 1;
    }
}

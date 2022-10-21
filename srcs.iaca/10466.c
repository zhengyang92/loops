#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef stbi__context;

int
fn (int channel, stbi_uc * dest, int mask, stbi__context * s)
{
  int i = 0x80;
  for (i = 0; i < 4; ++i, mask >>= 1)
     { IACA_START
      if (channel & mask)
	{
	  if (stbi__at_eof (s))
	    return ((unsigned char *) (size_t) (stbi__err ("bad file")
						? ((void *) 0) : ((void *)
								  0)));
	  dest[i] = stbi__get8 (s);
	}
} IACA_END }

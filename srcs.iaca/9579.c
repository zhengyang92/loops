#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t state, int VC1_CODE_SEQHDR, int i, const uint8_t * buf,
    int VC1_CODE_ENTRYPOINT, int buf_size, int VC1_CODE_RES0)
{
  int charged = 0;
  for (i = 0; i < buf_size; i++)
    {
      state = (state << 8) | buf[i];
      if ((((state) & ~0xFF) == VC1_CODE_RES0))
	{
	  if (state == VC1_CODE_SEQHDR || state == VC1_CODE_ENTRYPOINT)
	    {
	      charged = 1;
	    }
	  else if (charged)
	    {
	      return i - 3;
	    }
	}
    }
}

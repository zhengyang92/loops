#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef __uint8_t uint8_t;

int
fn (int i, GetByteContext cmds, int y_pos, int line_size, unsigned int count,
    GetByteContext * gb, uint8_t * dst, int height)
{
  int x_pos = 0;
  for (i = 0; i < count && x_pos < line_size; i++)
     { IACA_START
      int8_t cmd = bytestream2_get_byte (&cmds);
      int l, r;
      if (cmd == 0)
	{
	  l = bytestream2_get_be16 (gb);
	  while (l-- > 0 && x_pos < line_size)
	    {
	      dst[x_pos + y_pos * line_size] = bytestream2_get_byte (gb);
	      dst[x_pos + y_pos++ * line_size + 1] =
		bytestream2_get_byte (gb);
	      if (y_pos >= height)
		{
		  y_pos = 0;
		  x_pos += 2;
		}
	    }
	}
      else if (cmd < 0)
	{
	  l = -cmd;
	  while (l-- > 0 && x_pos < line_size)
	    {
	      dst[x_pos + y_pos * line_size] = bytestream2_get_byte (gb);
	      dst[x_pos + y_pos++ * line_size + 1] =
		bytestream2_get_byte (gb);
	      if (y_pos >= height)
		{
		  y_pos = 0;
		  x_pos += 2;
		}
	    }
	}
      else if (cmd == 1)
	{
	  l = bytestream2_get_be16 (gb);
	  r = bytestream2_get_be16 (gb);
	  while (l-- > 0 && x_pos < line_size)
	    {
	      dst[x_pos + y_pos * line_size] = r >> 8;
	      dst[x_pos + y_pos++ * line_size + 1] = r & 0xFF;
	      if (y_pos >= height)
		{
		  y_pos = 0;
		  x_pos += 2;
		}
	    }
	}
      else
	{
	  l = cmd;
	  r = bytestream2_get_be16 (gb);
	  while (l-- > 0 && x_pos < line_size)
	    {
	      dst[x_pos + y_pos * line_size] = r >> 8;
	      dst[x_pos + y_pos++ * line_size + 1] = r & 0xFF;
	      if (y_pos >= height)
		{
		  y_pos = 0;
		  x_pos += 2;
		}
	    }
	}
     } IACA_END
}

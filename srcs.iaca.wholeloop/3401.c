#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int dst_size, const unsigned char *src, int i, unsigned char *dst,
    int code_table[64], const unsigned char *src_end, int len)
{
  IACA_START for (i = 0; i < 64 && dst_size > 0; i++)
    {
      len = code_table[i];
      if (len < 0)
	{
	  len = -len;
	  if (src_end - src < 1)
	    return ((void *) 0);
	  memset (dst, *src++, ((len) > (dst_size) ? (dst_size) : (len)));
	}
      else
	{
	  if (src_end - src < len)
	    return ((void *) 0);
	  memcpy (dst, src, ((len) > (dst_size) ? (dst_size) : (len)));
	  src += len;
	} dst += len;
      dst_size -= len;
}IACA_END}

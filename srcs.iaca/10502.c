#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t src_len, const char *const *suffixes, const char *src_name)
{
  for (size_t i = 0; suffixes[i] != ((void *) 0); ++i)
     { IACA_START
      if (test_suffix (suffixes[i], src_name, src_len) != 0)
	{
	  msg_suffix (src_name, suffixes[i]);
	  return ((void *) 0);
	}
} IACA_END }

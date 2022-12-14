#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct microdvd_tag
{
  char key;
  int persistent;
  uint32_t data1;
  uint32_t data2;
  char *data_string;
  int data_string_len;
} microdvd_tag;

int
fn (int sidx, int i, struct microdvd_tag tags[8])
{
  int underline = 0;
  int italic = 0;
  int bold = 0;
  IACA_START for (sidx = 0; sidx < sizeof ("ibus") - 1; sidx++)
    {
      if (tags[i].data1 & (1 << sidx))
	{
	  switch ("ibus"[sidx])
	    {
	    case 'i':
	      italic = 1;
	      break;
	    case 'b':
	      bold = 1;
	      break;
	    case 'u':
	      underline = 1;
	      break;
	    }
	}
     } IACA_END
}

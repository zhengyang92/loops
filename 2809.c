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
fn (struct microdvd_tag tags[8], int i, int sidx)
{
  int underline = 0;
  int italic = 0;
  int bold = 0;
  for (sidx = 0; sidx < sizeof ("ibus") - 1; sidx++)
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
    }
}

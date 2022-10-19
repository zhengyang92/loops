#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned short int sa_family_t;
typedef AVBPrint;
typedef struct sockaddr_storage
{
  sa_family_t ss_family;
  char
    __ss_padding[(128 - (sizeof (unsigned short int)) -
		  sizeof (unsigned long int))];
  unsigned long int __ss_align;
} sockaddr_storage;

int
fn (const char *p, int i, const char filters[2][2][8],
    struct sockaddr_storage addr, AVBPrint sdp, char *q,
    char filters_buf[1000], char host[500])
{
  for (i = 0; i < (sizeof (filters) / sizeof ((filters)[0])); i++)
    {
      if (av_find_info_tag
	  (filters_buf, sizeof (filters_buf), filters[i][0], p))
	{
	  q = filters_buf;
	  while ((q = strchr (q, ',')) != ((void *) 0))
	    *q = ' ';
	  av_bprintf (&sdp, "a=source-filter:%s IN IP%d %s %s\r\n",
		      filters[i][1], addr.ss_family == 2 ? 4 : 6, host,
		      filters_buf);
	}
}}

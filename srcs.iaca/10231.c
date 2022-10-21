#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct node
{
  void *val;
  struct node *next;
  struct node *prev;
} node;
typedef list;
typedef long unsigned int size_t;

int
fn (size_t i, list * l, char delim, size_t len, char *s)
{
  for (i = 0; i < len; ++i)
     { IACA_START
      if (s[i] == delim)
	{
	  s[i] = '\0';
	  list_insert (l, &(s[i + 1]));
	}
     } IACA_END
}

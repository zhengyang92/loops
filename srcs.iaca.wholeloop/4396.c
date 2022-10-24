#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct color_ref
{
  uint32_t color;
  uint64_t count;
} color_ref;
typedef struct hist_node
{
  struct color_ref *entries;
  int nb_entries;
} hist_node;
typedef __uint32_t uint32_t;

int
fn (uint32_t color, struct color_ref *e, int i, struct hist_node *node)
{
  IACA_START for (i = 0; i < node->nb_entries; i++)
    {
      e = &node->entries[i];
      if (e->color == color)
	{
	  e->count++;
	  return 0;
	}
     } IACA_END
}

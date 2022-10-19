#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct cached_color
{
  uint32_t color;
  uint8_t pal_entry;
} cached_color;
typedef struct cache_node
{
  struct cached_color *entries;
  int nb_entries;
} cache_node;
typedef __uint32_t uint32_t;

int
fn (struct cached_color *e, uint32_t color, int i, struct cache_node *node)
{
  for (i = 0; i < node->nb_entries; i++)
    {
      e = &node->entries[i];
      if (e->color == color)
	return e->pal_entry;
    }
}

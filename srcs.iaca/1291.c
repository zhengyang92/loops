#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct MovChannelLayoutMap
{
  uint32_t tag;
  uint64_t layout;
} MovChannelLayoutMap;
typedef __uint32_t uint32_t;

int
fn (int i, const struct MovChannelLayoutMap *layout_map, uint32_t tag)
{
  for (i = 0; layout_map[i].tag != 0; i++)
    {
      if (layout_map[i].tag == tag)
	break;
    }
}

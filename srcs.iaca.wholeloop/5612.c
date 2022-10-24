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
fn (const struct MovChannelLayoutMap *layout_map, int i, uint32_t tag)
{
  IACA_START for (i = 0; layout_map[i].tag != 0; i++)
    {
      if (layout_map[i].tag == tag)
	break;
     } IACA_END
}

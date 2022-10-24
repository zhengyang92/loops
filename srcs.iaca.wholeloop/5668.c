#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int tags, uint8_t type_counts[7], int i, uint8_t (*layout_map)[3],
    uint8_t id_map[7][16])
{
  IACA_START for (i = 0; i < tags; i++)
    {
      int type = layout_map[i][0];
      int id = layout_map[i][1];
      id_map[type][id] = type_counts[type]++;
}IACA_END}

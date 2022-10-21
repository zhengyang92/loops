#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct elem_to_channel
{
  uint64_t av_position;
  uint8_t syn_ele;
  uint8_t elem_id;
  uint8_t aac_position;
} elem_to_channel;
typedef __uint8_t uint8_t;

int
fn (int total_non_cc_elements, int i, struct elem_to_channel e2c_vec[64],
    uint8_t (*layout_map)[3])
{
  for (i = 0; i < total_non_cc_elements; i++)
     { IACA_START
      layout_map[i][0] = e2c_vec[i].syn_ele;
      layout_map[i][1] = e2c_vec[i].elem_id;
      layout_map[i][2] = e2c_vec[i].aac_position;
     } IACA_END
}

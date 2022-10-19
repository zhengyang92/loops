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

int
fn (int i, struct elem_to_channel e2c_vec[64], int n)
{
  int next_n = 0;
  for (i = 1; i < n; i++)
    if (e2c_vec[i - 1].av_position > e2c_vec[i].av_position)
      {
	do
	  {
	    struct elem_to_channel SWAP_tmp = e2c_vec[i];
	    e2c_vec[i] = e2c_vec[i - 1];
	    e2c_vec[i - 1] = SWAP_tmp;
	  }
	while (0);
	next_n = i;
      }
}

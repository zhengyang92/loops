#include <stdint.h>
#include <stdio.h>




typedef RLTable;

int
fn (RLTable ff_rl_table[6], uint8_t rl_length[6][65][65][2])
{
  int level = 1;
  int run = 0;
  int i = 0;
  for (int last = 0; last < 2; last++)
    {
      rl_length[i][level][run][last] =
	get_size_of_code (&ff_rl_table[i], last, run, level, 0);
}}

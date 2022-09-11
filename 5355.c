#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int table_size, int16_t (*table)[2])
{
  for (int i = 0; i < table_size; i++)
    {
      if (table[i][1] == 0)
	table[i][0] = -1;
    }
}

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (uint64_t * K, uint64_t CDn, int i, const uint8_t PC2_shuffle[48])
{
  for (i = 0; i < 16; i++)
    {
      CDn = key_shift_left (CDn);
      if (i > 1 && i != 8 && i != 15)
	CDn = key_shift_left (CDn);
      K[i] = shuffle (CDn, PC2_shuffle, sizeof (PC2_shuffle));
    }
}

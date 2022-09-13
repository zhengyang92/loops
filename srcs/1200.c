#include <stdint.h>
#include <stdio.h>




typedef struct toc_entry
{
  uint32_t offset;
  uint32_t size;
} toc_entry;
typedef __int64_t int64_t;
typedef __uint32_t uint32_t;

int
fn (int largest_idx, uint32_t toc_size, int64_t largest_size,
    struct toc_entry TOC[16], int64_t current_size)
{
  for (uint32_t i = 1; i < toc_size; i++)
    {
      current_size = TOC[i].size;
      if (current_size > largest_size)
	{
	  largest_idx = i;
	  largest_size = current_size;
	}
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (const int buffer_linesize, int i, const int nb_match_blocks,
    float *rbuffer, int k, float *bufferz, float *rbufferz, int j,
    const int block_size, float *buffer)
{
  for (k = 0; k < nb_match_blocks; k++)
    {
      bufferz[k] = buffer[buffer_linesize * k + i * block_size + j];
      rbufferz[k] = rbuffer[buffer_linesize * k + i * block_size + j];
    }
}

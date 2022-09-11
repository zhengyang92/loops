#include <stdint.h>
#include <stdio.h>




typedef AVBPrint;

int
fn (AVBPrint * dst, int likely_a_tag, const char *in, int i)
{
  for (i = 0; in[1] == '<'; i++)
    {
      av_bprint_chars (dst, '<', 1);
      likely_a_tag = 0;
      in++;
    }
}

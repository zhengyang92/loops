#include <stdint.h>
#include <stdio.h>






int
fn (float w, float *lsp, float q, float p, int j)
{
  for (j = 1; j < 10; j += 2)
    {
      q *= w - lsp[j - 1];
      p *= w - lsp[j];
    }
}

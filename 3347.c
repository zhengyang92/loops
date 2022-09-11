#include <stdint.h>
#include <stdio.h>






int
fn (const float *old_lsp, float *lsp, const float *new_lsp, float margin,
    const float tmp, int len)
{
  for (int i = 0; i < len; i++)
    {
      lsp[i] = (1.f - tmp) * old_lsp[i] + tmp * new_lsp[i];
      lsp[i] = av_clipf_sse (lsp[i], margin, 3.14159265358979323846 - margin);
}}

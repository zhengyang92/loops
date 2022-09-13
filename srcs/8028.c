#include <stdint.h>
#include <stdio.h>




typedef float OUT_INT;
typedef long int ptrdiff_t;
typedef float MPA_INT;

int
fn (ptrdiff_t incr, MPA_INT * synth_buf, const MPA_INT * w, int j, float sum,
    const MPA_INT * p, OUT_INT * samples, float sum2, const MPA_INT * w2,
    OUT_INT * samples2)
{
  for (j = 1; j < 16; j++)
    {
      sum2 = 0;
      p = synth_buf + 16 + j;
      {
	float tmp;
	tmp = p[0 * 64];
	sum += ((w)[0 * 64]) * (tmp);
	sum2 -= ((w2)[0 * 64]) * (tmp);
	tmp = p[1 * 64];
	sum += ((w)[1 * 64]) * (tmp);
	sum2 -= ((w2)[1 * 64]) * (tmp);
	tmp = p[2 * 64];
	sum += ((w)[2 * 64]) * (tmp);
	sum2 -= ((w2)[2 * 64]) * (tmp);
	tmp = p[3 * 64];
	sum += ((w)[3 * 64]) * (tmp);
	sum2 -= ((w2)[3 * 64]) * (tmp);
	tmp = p[4 * 64];
	sum += ((w)[4 * 64]) * (tmp);
	sum2 -= ((w2)[4 * 64]) * (tmp);
	tmp = p[5 * 64];
	sum += ((w)[5 * 64]) * (tmp);
	sum2 -= ((w2)[5 * 64]) * (tmp);
	tmp = p[6 * 64];
	sum += ((w)[6 * 64]) * (tmp);
	sum2 -= ((w2)[6 * 64]) * (tmp);
	tmp = p[7 * 64];
	sum += ((w)[7 * 64]) * (tmp);
	sum2 -= ((w2)[7 * 64]) * (tmp);
      };
      p = synth_buf + 48 - j;
      {
	float tmp;
	tmp = p[0 * 64];
	sum -= ((w + 32)[0 * 64]) * (tmp);
	sum2 -= ((w2 + 32)[0 * 64]) * (tmp);
	tmp = p[1 * 64];
	sum -= ((w + 32)[1 * 64]) * (tmp);
	sum2 -= ((w2 + 32)[1 * 64]) * (tmp);
	tmp = p[2 * 64];
	sum -= ((w + 32)[2 * 64]) * (tmp);
	sum2 -= ((w2 + 32)[2 * 64]) * (tmp);
	tmp = p[3 * 64];
	sum -= ((w + 32)[3 * 64]) * (tmp);
	sum2 -= ((w2 + 32)[3 * 64]) * (tmp);
	tmp = p[4 * 64];
	sum -= ((w + 32)[4 * 64]) * (tmp);
	sum2 -= ((w2 + 32)[4 * 64]) * (tmp);
	tmp = p[5 * 64];
	sum -= ((w + 32)[5 * 64]) * (tmp);
	sum2 -= ((w2 + 32)[5 * 64]) * (tmp);
	tmp = p[6 * 64];
	sum -= ((w + 32)[6 * 64]) * (tmp);
	sum2 -= ((w2 + 32)[6 * 64]) * (tmp);
	tmp = p[7 * 64];
	sum -= ((w + 32)[7 * 64]) * (tmp);
	sum2 -= ((w2 + 32)[7 * 64]) * (tmp);
      };
      *samples = round_sample (&sum);
      samples += incr;
      sum += sum2;
      *samples2 = round_sample (&sum);
      samples2 -= incr;
      w++;
      w2--;
}}

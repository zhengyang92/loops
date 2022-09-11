#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int linesize, int temp[64], int i, uint8_t * dest)
{
  for (i = 0; i < 8; i++)
    {
      {
	const int a0 = ((&temp[8 * i]))[0] + ((&temp[8 * i]))[4];
	const int a1 = ((&temp[8 * i]))[0] - ((&temp[8 * i]))[4];
	const int a2 = ((&temp[8 * i]))[2] + ((&temp[8 * i]))[6];
	const int a3 =
	  (2896 * (((&temp[8 * i]))[2] - ((&temp[8 * i]))[6])) >> 11;
	const int a4 = ((&temp[8 * i]))[5] + ((&temp[8 * i]))[3];
	const int a5 = ((&temp[8 * i]))[5] - ((&temp[8 * i]))[3];
	const int a6 = ((&temp[8 * i]))[1] + ((&temp[8 * i]))[7];
	const int a7 = ((&temp[8 * i]))[1] - ((&temp[8 * i]))[7];
	const int b0 = a4 + a6;
	const int b1 = (3784 * (a5 + a7)) >> 11;
	const int b2 = ((-5352 * a5) >> 11) - b0 + b1;
	const int b3 = (2896 * (a6 - a4) >> 11) - b2;
	const int b4 = ((2217 * a7) >> 11) + b3 - b1;
	((&dest[i * linesize]))[0] = (((a0 + a2 + b0) + 0x7F) >> 8);
	((&dest[i * linesize]))[1] = (((a1 + a3 - a2 + b2) + 0x7F) >> 8);
	((&dest[i * linesize]))[2] = (((a1 - a3 + a2 + b3) + 0x7F) >> 8);
	((&dest[i * linesize]))[3] = (((a0 - a2 - b4) + 0x7F) >> 8);
	((&dest[i * linesize]))[4] = (((a0 - a2 + b4) + 0x7F) >> 8);
	((&dest[i * linesize]))[5] = (((a1 - a3 + a2 - b3) + 0x7F) >> 8);
	((&dest[i * linesize]))[6] = (((a1 + a3 - a2 - b2) + 0x7F) >> 8);
	((&dest[i * linesize]))[7] = (((a0 + a2 - b0) + 0x7F) >> 8);
      };
}}

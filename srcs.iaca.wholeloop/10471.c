#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int stbi__flip_vertically_on_write, float UDU[64], int col,
    const unsigned char *imageData, int width, float VDU[64], int x,
    float YDU[64], int ofsG, int row, int ofsB, int height, int pos, int comp)
{
  IACA_START for (col = x; col < x + 8; ++col, ++pos)
    {
      int p =
	(stbi__flip_vertically_on_write ? height - 1 -
	 row : row) * width * comp + col * comp;
      float r, g, b;
      if (row >= height)
	{
	  p -= width * comp * (row + 1 - height);
	}
      if (col >= width)
	{
	  p -= comp * (col + 1 - width);
	}
      r = imageData[p + 0];
      g = imageData[p + ofsG];
      b = imageData[p + ofsB];
      YDU[pos] = +0.29900f * r + 0.58700f * g + 0.11400f * b - 128;
      UDU[pos] = -0.16874f * r - 0.33126f * g + 0.50000f * b;
      VDU[pos] = +0.50000f * r - 0.41869f * g - 0.08131f * b;
     } IACA_END
}

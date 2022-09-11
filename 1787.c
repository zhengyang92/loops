#include <stdint.h>
#include <stdio.h>




typedef struct Screen
{
  uint8_t characters[15 + 1][32 + 1];
  uint8_t charsets[15 + 1][32 + 1];
  uint8_t colors[15 + 1][32 + 1];
  uint8_t bgs[15 + 1][32 + 1];
  uint8_t fonts[15 + 1][32 + 1];
  int16_t row_used;
} Screen;

int
fn (int CCSET_BASIC_AMERICAN, int j, int i, struct Screen *screen)
{
  int tab = 0;
  for (i = 0; screen->row_used && i < 15; i++)
    {
      if (((screen->row_used) & (1 << (i))))
	{
	  const char *row = screen->characters[i];
	  const char *charset = screen->charsets[i];
	  j = 0;
	  while (row[j] == ' ' && charset[j] == CCSET_BASIC_AMERICAN)
	    j++;
	  if (!tab || j < tab)
	    tab = j;
	}
    }
}

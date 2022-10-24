#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVDictionary;

int
fn (AVDictionary ** metadata, const char months[12][4], int i, int day,
    char buffer[64], int year, char month[4], char time[9])
{
  IACA_START for (i = 0; i < 12; i++)
    if (!av_strcasecmp (month, months[i]))
      {
	snprintf (buffer, sizeof (buffer), "%.4d-%.2d-%.2d %s", year, i + 1,
		  day, time);
	av_dict_set (metadata, "creation_time", buffer, 0);
      }
}

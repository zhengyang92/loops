#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct chord
{
  int x;
  int y;
  int l;
  int i;
} chord;
typedef struct chord_set
{
  chord *C;
  int size;
  int cap;
  int *R;
  int Lnum;
  int minX;
  int maxX;
  int minY;
  int maxY;
  unsigned nb_elements;
} chord_set;

int
fn (chord_set * chords, int val)
{
  int r_cap = 1;
  for (int i = 0; i < chords->size; i++)
    {
      if (val != chords->C[i].l)
	{
	  while (2 * val < chords->C[i].l && val != 0)
	    {
	      if (chords->Lnum >= r_cap)
		{
		  chords->R =
		    av_realloc_f (chords->R, r_cap * 2, sizeof (*chords->R));
		  if (!chords->R)
		    return (-(12));
		  r_cap *= 2;
		}
	      chords->R[chords->Lnum++] = 2 * val;
	      val *= 2;
	    }
	  val = chords->C[i].l;
	  if (chords->Lnum >= r_cap)
	    {
	      chords->R =
		av_realloc_f (chords->R, r_cap * 2, sizeof (*chords->R));
	      if (!chords->R)
		return (-(12));
	      r_cap *= 2;
	    }
	  chords->R[chords->Lnum++] = val;
	}
    }
}

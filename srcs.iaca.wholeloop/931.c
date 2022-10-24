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
fn (chord_set * chords, int chord_length_index)
{
  IACA_START for (int i = 0; i < chords->size; i++)
    {
      while (chords->R[chord_length_index] < chords->C[i].l)
	chord_length_index++;
      chords->C[i].i = chord_length_index;
     } IACA_END
}

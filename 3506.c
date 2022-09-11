#include <stdint.h>
#include <stdio.h>




typedef struct vorbis_floor1_entry
{
  uint16_t x;
  uint16_t sort;
  uint16_t low;
  uint16_t high;
} vorbis_floor1_entry;
typedef struct vorbis_floor1_s
{
  uint8_t partitions;
  uint8_t partition_class[32];
  uint8_t class_dimensions[16];
  uint8_t class_subclasses[16];
  uint8_t class_masterbook[16];
  int16_t subclass_books[16][8];
  uint8_t multiplier;
  uint16_t x_list_dim;
  vorbis_floor1_entry *list;
} vorbis_floor1_s;
typedef __uint16_t uint16_t;
typedef struct vorbis_floor1_s vorbis_floor1;

int
fn (unsigned int i, int adx, vorbis_floor1 * vf, int dy, int err,
    unsigned int range, int off, int floor1_flag[258], int predicted,
    uint16_t floor1_Y_final[258], uint16_t floor1_Y[258], int ady)
{
  for (i = 2; i < vf->x_list_dim; ++i)
    {
      unsigned val, highroom, lowroom, room, high_neigh_offs, low_neigh_offs;
      low_neigh_offs = vf->list[i].low;
      high_neigh_offs = vf->list[i].high;
      dy = floor1_Y_final[high_neigh_offs] - floor1_Y_final[low_neigh_offs];
      adx = vf->list[high_neigh_offs].x - vf->list[low_neigh_offs].x;
      ady = ((dy) >= 0 ? (dy) : (-(dy)));
      err = ady * (vf->list[i].x - vf->list[low_neigh_offs].x);
      off = err / adx;
      if (dy < 0)
	{
	  predicted = floor1_Y_final[low_neigh_offs] - off;
	}
      else
	{
	  predicted = floor1_Y_final[low_neigh_offs] + off;
	}
      val = floor1_Y[i];
      highroom = range - predicted;
      lowroom = predicted;
      if (highroom < lowroom)
	{
	  room = highroom * 2;
	}
      else
	{
	  room = lowroom * 2;
	}
      if (val)
	{
	  floor1_flag[low_neigh_offs] = 1;
	  floor1_flag[high_neigh_offs] = 1;
	  floor1_flag[i] = 1;
	  if (val >= room)
	    {
	      if (highroom > lowroom)
		{
		  floor1_Y_final[i] =
		    av_clip_uint16_c (val - lowroom + predicted);
		}
	      else
		{
		  floor1_Y_final[i] =
		    av_clip_uint16_c (predicted - val + highroom - 1);
		}
	    }
	  else
	    {
	      if (val & 1)
		{
		  floor1_Y_final[i] =
		    av_clip_uint16_c (predicted - (val + 1) / 2);
		}
	      else
		{
		  floor1_Y_final[i] = av_clip_uint16_c (predicted + val / 2);
		}
	    }
	}
      else
	{
	  floor1_flag[i] = 0;
	  floor1_Y_final[i] = av_clip_uint16_c (predicted);
	}
      do
	{
	  if (0)
	    av_log (((void *) 0), 48, " Decoded floor(%d) = %u / val %u\n",
		    vf->list[i].x, floor1_Y_final[i], val);
	}
      while (0);
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct exif_tag
{
  char name[32];
  uint16_t id;
} exif_tag;
typedef __uint16_t uint16_t;

int
fn (const struct exif_tag tag_list[117], int i, uint16_t id)
{
  for (i = 0; i < (sizeof (tag_list) / sizeof ((tag_list)[0])); i++)
    {
      if (tag_list[i].id == id)
	return tag_list[i].name;
    }
}

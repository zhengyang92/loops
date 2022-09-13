#include <stdint.h>
#include <stdio.h>




typedef AVDictionary;
typedef struct section
{
  int id;
  const char *name;
  int flags;
  int children_ids[10 + 1];
  const char *element_name;
  const char *unique_name;
  AVDictionary *entries_to_show;
  int show_all_entries;
} section;

int
fn (int i, const char *section_name, struct section sections[48],
    int show_all_entries, AVDictionary * entries)
{
  int ret = 0;
  for (i = 0; i < (sizeof (sections) / sizeof ((sections)[0])); i++)
    {
      const struct section *section = &sections[i];
      if (!strcmp (section_name, section->name)
	  || (section->unique_name
	      && !strcmp (section_name, section->unique_name)))
	{
	  av_log (((void *) 0), 48,
		  "'%s' matches section with unique name '%s'\n",
		  section_name, (char *) av_x_if_null (section->unique_name,
						       section->name));
	  ret++;
	  mark_section_show_entries (section->id, show_all_entries, entries);
	}
}}

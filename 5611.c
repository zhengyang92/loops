#include <stdint.h>
#include <stdio.h>


enum AVOptionType
{ AV_OPT_TYPE_FLAGS, AV_OPT_TYPE_INT, AV_OPT_TYPE_INT64, AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT, AV_OPT_TYPE_STRING, AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY, AV_OPT_TYPE_DICT, AV_OPT_TYPE_CONST = 128, };
enum AVIODataMarkerType
{ AVIO_DATA_MARKER_HEADER, AVIO_DATA_MARKER_SYNC_POINT,
    AVIO_DATA_MARKER_BOUNDARY_POINT, AVIO_DATA_MARKER_UNKNOWN,
    AVIO_DATA_MARKER_TRAILER };

typedef struct AVRational
{
  int num;
  int den;
} AVRational;
typedef struct AVOption
{
  const char *name;
  const char *help;
  int offset;
  enum AVOptionType type;
  union
  {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
  } default_val;
  double min;
  double max;
  int flags;
  const char *unit;
} AVOption;
typedef struct AVClass
{
  const char *class_name;
  const char *(*item_name) (void *ctx);
  const struct AVOption *option;
  int version;
  int log_level_offset_offset;
  int parent_log_context_offset;
  void *(*child_next) (void *obj, void *prev);
  const struct AVClass *(*child_class_next) (const struct AVClass * prev);
} AVClass;
typedef AVIOContext;

int
fn (int display_matrix[3][3], int i, AVIOContext * pb)
{
  for (i = 0; i < 3; i++)
    {
      display_matrix[i][0] = avio_rb32 (pb);
      display_matrix[i][1] = avio_rb32 (pb);
      display_matrix[i][2] = avio_rb32 (pb);
    }
}

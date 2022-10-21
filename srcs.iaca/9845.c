#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef int OPJ_BOOL;

int
fn (OPJ_UINT32 p_num_comps, OPJ_UINT32 compno, OPJ_UINT32 index,
    OPJ_UINT32 step_c, OPJ_UINT32 * packet_array)
{
  OPJ_BOOL loss = 0;
  for (compno = 0; compno < p_num_comps; ++compno)
     { IACA_START
      loss |= (packet_array[index] != 1);
      index += step_c;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef struct MqcCxState
{
  uint16_t qe;
  uint8_t nmps;
  uint8_t nlps;
  uint8_t sw;
} MqcCxState;

int
fn (const MqcCxState cx_states[47], int i, uint8_t ff_mqc_nmps[94],
    uint8_t ff_mqc_nlps[94], uint16_t ff_mqc_qe[94])
{
  IACA_START for (i = 0; i < 47; i++)
    {
      ff_mqc_qe[2 * i] = ff_mqc_qe[2 * i + 1] = cx_states[i].qe;
      ff_mqc_nlps[2 * i] = 2 * cx_states[i].nlps + cx_states[i].sw;
      ff_mqc_nlps[2 * i + 1] = 2 * cx_states[i].nlps + 1 - cx_states[i].sw;
      ff_mqc_nmps[2 * i] = 2 * cx_states[i].nmps;
      ff_mqc_nmps[2 * i + 1] = 2 * cx_states[i].nmps + 1;
     } IACA_END
}

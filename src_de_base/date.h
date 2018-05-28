#include "const.h"
#include "ecran.h"
#include "stdlib.h"
#include "segment.h"

uint8_t lit_CMOS(uint8_t reg);
void affiche_date(void);
void set_rtc_freq(uint8_t d);
void traitant_IT_40();
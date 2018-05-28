#include "const.h"
#include "ecran.h"
#include "stdlib.h"
#include "segment.h"

void tic_PIT(void);
void set_freq(void);
void init_traitant(void (*traitant)(void), uint8_t n_interrupt);
void traitant_IT_32();
void demasque(uint32_t n_irq);
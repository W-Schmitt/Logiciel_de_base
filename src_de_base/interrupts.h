#include "const.h"
#include "ecran.h"
#include "stdlib.h"
#include "segment.h"

/**
 * Initialise un traitant en encodant son adresse dans la table des
 * interruptions
 */
void init_traitant(void (*traitant)(void), uint8_t n_interrupt);

/**
 * Démasque une IRQ
 */
void demasque(uint32_t n_irq);

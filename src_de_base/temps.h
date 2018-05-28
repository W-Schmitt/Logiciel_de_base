#include "const.h"
#include "ecran.h"
#include "stdlib.h"
#include "segment.h"
#include "interrupts.h"

/**
 * Traite une interruption de la clock
 */
void tic_PIT(void);

/**
 * Définit la valeur de la fréquence de la clock
 */
void set_freq(void);

/**
 * Déclaration pour la fonction assembleur correspondante
 */
void traitant_IT_32();
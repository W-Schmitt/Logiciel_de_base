#include "const.h"
#include "ecran.h"
#include "stdlib.h"
#include "segment.h"
#include "date.h"

/**
 * Gère les interruptions 40
 */
void interrupt_clavier(void);

/**
 * Récupère le caractère associé au scancode (de mon clavier, tout ne fonctionne
 *  peut-être pas)
 */
char get_charcode(uint8_t o);

/**
 * Déclaration pour la fonction assembleur associée
 */
void traitant_IT_33(void);
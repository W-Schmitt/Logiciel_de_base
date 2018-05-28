#include "const.h"
#include "ecran.h"
#include "stdlib.h"
#include "segment.h"

/**
 * Lit le CMOS pour en sortir la date (RTC)
 */
uint8_t lit_CMOS(uint8_t reg);

/**
 * Affiche la date en haut à gauche de l'écran
 */
void affiche_date(void);

/**
 * Définit la fréquence de la RTC
 */
void set_rtc_freq(uint8_t d);

/**
 * Définition pour la fonction assembleur associée
 */
void traitant_IT_40();
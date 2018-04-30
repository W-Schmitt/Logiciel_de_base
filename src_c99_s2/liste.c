#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

struct cell_t {
    uint8_t val;
    struct cell_t *suiv;
};

struct liste_t {
    struct cell_t tete;
};

struct liste_t *nouv_liste(void)
{
    // a changer
    return NULL;
}

bool est_vide_liste(struct liste_t *liste)
{
    // a changer
    // le compilateur genere un avertissement si on n'utilise
    //   pas un parametre ou une variable declare
    // pour eviter ca, il suffit de le transtyper vers void
    (void)liste;
    return false;
}

void inserer_tete_liste(uint8_t val, struct liste_t *liste)
{
    // a completer
    (void)val;
    (void)liste;
}

bool supprimer_val_liste(uint8_t val, struct liste_t *liste)
{
    // a changer
    (void)val;
    (void)liste;
    return false;
}

void afficher_liste(struct liste_t *liste)
{
    // a completer
    (void)liste;
}

void detruire_liste(struct liste_t **liste)
{
    // a completer
    (void)liste;
}


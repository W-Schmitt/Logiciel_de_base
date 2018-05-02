#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>

struct cell_t {
    uint8_t val;
    struct cell_t *suiv;
};

struct liste_t {
    struct cell_t tete;
};

/**
 * Initialise une liste chaînée.
 */
struct liste_t *nouv_liste(void)
{
    struct liste_t *l = malloc(sizeof(struct liste_t));
    assert(l != NULL);
    l->tete.suiv = NULL;
    return l;
}

/**
 *
 */
bool est_vide_liste(struct liste_t *liste)
{
    return liste->tete.suiv == NULL;
}

/**
 * Insère un élément en tête de liste
 */
void inserer_tete_liste(uint8_t val, struct liste_t *liste)
{
    struct cell_t *tmp = malloc(sizeof(*tmp));
    assert(tmp != NULL);
    tmp->val = val;
    tmp->suiv = liste->tete.suiv;
    liste->tete.suiv = tmp;
}

bool supprimer_val_liste(uint8_t val, struct liste_t *liste)
{
    struct cell_t *current;
    struct cell_t *previous;
    current = &(liste->tete);
    previous = current;
    do {
        if (current->val == val) {
            previous->suiv = current->suiv;
            free(current);
            return true;
        }
        previous = current;
        current = current->suiv;
    } while (current->val);
    return false;
}

void afficher_liste(struct liste_t *liste)
{
    uint32_t i = 0;
    struct cell_t current = liste->tete;
    do {
        printf("|%" PRId32 "\t|\t%" PRId8 "|\n", i, current.val);
        current = *current.suiv;
        i++;
    } while (current.val);
}

void detruire_liste(struct liste_t **liste)
{
    struct cell_t *current = &((*liste)->tete);
    struct cell_t *next = current->suiv;
    while (next != NULL) {
        free(current);
        current = next;
        next = current->suiv;
    }
    free(next);
    free(*liste);
    *liste = NULL;
}


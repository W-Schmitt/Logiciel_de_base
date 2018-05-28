#include "liste.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define TAILLE_TABLE 4

/**
 * Struct définie ici = privée !
 */
struct tablehash_t {
    uint64_t nbr_elem;
    struct liste_t *table[TAILLE_TABLE];
};

static int64_t hash(uint8_t x)
{
    return x % TAILLE_TABLE;
}

struct tablehash_t *nouv_tablehash(void)
{
    struct tablehash_t *ht = malloc(sizeof(struct tablehash_t));
    assert(ht != NULL);
    ht->nbr_elem = 0;
    return ht;
}

bool est_vide_tablehash(struct tablehash_t *th)
{
    for (uint8_t i = 0; i < TAILLE_TABLE; i++) {
        if (!est_vide_liste(th->table[i])) {
            return false;
        }
    }
    return true;
}

void inserer_val_tablehash(uint8_t val, struct tablehash_t *th)
{
    struct liste_t *l = th->table[hash(val)];
    inserer_tete_liste(val, l);
}

void supprimer_val_tablehash(uint8_t val, struct tablehash_t *th)
{
    struct liste_t *l = th->table[hash(val)];
    supprimer_val_liste(val, l);
}

void afficher_tablehash(struct tablehash_t *th)
{
    for (uint8_t i = 0; i < TAILLE_TABLE; i++) {
        afficher_liste(th->table[i]);
    }
}

void detruire_tablehash(struct tablehash_t **th)
{
    for (uint8_t i = 0; i < TAILLE_TABLE; i++) {
        detruire_liste(&((*th)->table[i]));
    }
    free(*th);
    *th = NULL;
}


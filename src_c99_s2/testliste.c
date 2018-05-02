#include "liste.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t cnt = 0;
uint8_t passed = 0;

char* test(bool a) {
    if (a) {
        passed++;
    }
    cnt++;
    return a ? "true" : "false";
}

void report(void) {
    printf("\n==================\n");
    printf("Report\n");
    printf("==================\n");
    printf("Passed: \t%" PRIu8 "\n", passed);
    printf("Failed: \t%" PRIu8 "\n", cnt-passed);
    printf("Total:  \t%" PRIu8 "\n", cnt);
    printf("==================\n");
}

int main(void)
{
    // la fonction srandom initialise le generateur de
    //   nombres aleatoires
    srandom(time(NULL));
    // ensuite, on utilise random() pour recuperer une valeur
    //   aleatoire entre 0 et une valeur max tres grande
    // si on veut par exemple recuperer des entiers entre 0 et
    //   9, on utilisera un modulo : random() % 10

    printf("nouv_liste crée une liste vide.\n");
    struct liste_t *l = nouv_liste();
    printf("\t -> %s\n", test(est_vide_liste(l)));


    printf("inserer_tete_liste insère des éléments dans la liste.\n");
    uint8_t val;
    for (uint8_t i = 0; i < 10; i++) {
        val = random() % 10;
        inserer_tete_liste(val, l);
    }
    printf("\t -> %s\n", test(!est_vide_liste(l)));

    afficher_liste(l);

    struct liste_t *l2;
    l2 = nouv_liste();
    printf("detruire_liste supprime la liste.\n");
    detruire_liste(&l2);
    printf("\t -> %s\n", test(l2 == NULL));



    report();
    return 0;
}


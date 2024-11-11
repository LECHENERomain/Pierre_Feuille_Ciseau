#include <stdbool.h>
#include <stdio.h>
#include "main.h"

#include <stdlib.h>
#include <time.h>

int main(void) {
    int gagnantJ, gagnantO = 0;
    int choixJ;
    int choixOrdi;
    // 0 = pierre, 1 = feuille, 2 = ciseau
    srand(time(NULL));
    do {
        choixJ = choixJoueur();
        choixOrdi = choixOrdinateur();

        printf("L'ordinateur a choisi : %d\n", choixOrdi);

        if ( (choixJ == 0 && choixOrdi == 2) || (choixJ == 1 && choixOrdi == 0) || (choixJ == 2 && choixOrdi == 1) ) {
            gagnantJ = 1;
        }

        if ( (choixOrdi == 0 && choixJ == 2) || (choixOrdi == 1 && choixJ == 0) || (choixOrdi == 2 && choixJ == 1) ) {
            gagnantO = 1;
        }
    } while (!gagnantJ && !gagnantO);

    if (gagnantJ) printf("Vous avez gagne !");
    else printf("Vous avez perdu ...");


    return 0;
}

int choixJoueur() {
    int choix = -1;
    printf("Choisissez votre coup :\n");
    printf("Pierre = 0, Feuille = 1, Ciseaux = 2\n");

    // Lire un entier en utilisant scanf
    while (scanf("%d", &choix) != 1 || choix < 0 || choix > 2) {
        printf("Entree invalide. Veuillez entrer 0, 1 ou 2 : ");
        while (getchar() != '\n');
    }
    return choix;
}

char choixOrdinateur() {
    return rand()%3;
}
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 1000000

int saisir_tableau(float *t);
void afficher_tableau(float *t, int taille);
void tri_bulles(float *t, int taille_t);

int main() {
    float tableau[TAILLE_MAX];
    int taille;

    printf(" saisir la taille du tableau, puis ses valeurs :\n");
    taille = saisir_tableau(tableau);

    printf("tableau avant tri :\n");
    afficher_tableau(tableau, taille);

    tri_bulles(tableau, taille);

    printf("tableau après tri :\n");
    afficher_tableau(tableau, taille);

    return 0;
}

int saisir_tableau(float *t) {
    int i, taille;
    scanf("%d", &taille);
    if (taille > TAILLE_MAX) {
        printf("La taille dépasse la taille maximale possible.\n");
        exit(1);
    } else {
        for (i = 0; i < taille; i++) {
            scanf("%f", &t[i]);
        }
    }
    return taille;
}

void afficher_tableau(float *t, int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        printf("%.2f ", t[i]);
    }
    printf("\n");
}

void tri_bulles(float *t, int taille_t) {
    int i, j;
    for (i = taille_t - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (t[j+1] < t[j]) {
                float temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }
}



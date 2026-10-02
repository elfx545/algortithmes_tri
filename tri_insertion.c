#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000000

int saisir_tableau(float *t);
void afficher_tableau(float *t, int taille);
void tri_insertion(float *t, int taille_t);

int main() {
    float tableau[TAILLE_MAX];
    int taille;
    printf("Saisir la taille du tableau, puis ses valeurs :\n");
    taille = saisir_tableau(tableau);
    printf("Tableau avant tri :\n");
    afficher_tableau(tableau, taille);
    tri_insertion(tableau, taille);
    printf("Tableau après tri :\n");
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

void tri_insertion(float *t, int taille_t) {
    int i, j;
    float temp;
    for (i = 1; i < taille_t; i++) {
        temp = t[i];
        j = i;
        while (j > 0 && t[j-1] > temp) {
            t[j] = t[j-1];
            j--;
        }
        t[j] = temp;
    }
}


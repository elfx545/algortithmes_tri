#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000000

int saisir_tableau(float *t);
void afficher_tableau(float *t, int taille);
void tri_selection(float *t, int taille_t);

int main() {
    float tableau[TAILLE_MAX];
    int taille;
    printf("Saisir la taille du tableau puis ses valeurs :\n");
    taille = saisir_tableau(tableau);
    printf("Tableau avant tri :\n");
    afficher_tableau(tableau, taille);
    tri_selection(tableau, taille);
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

void tri_selection(float *t, int taille_t) {
    int i, j, m;
    float temp;
    for (i = 0; i < taille_t - 1; i++) {
        m = i;
        for (j = i + 1; j < taille_t; j++) {
            if (t[j] < t[m]) {
                m = j;
            }
        }
        if (m != i) {
            // Échange t[i] et t[m]
            temp = t[i];
            t[i] = t[m];
            t[m] = temp;
        }
    }
}


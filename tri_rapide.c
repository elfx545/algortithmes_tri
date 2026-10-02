#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000000

int saisir_tableau(float *t);
void afficher_tableau(float *t, int taille);
void tri_selection(float *t, int taille_t);
void tri_rapide_rec(float *t, int i_debut, int i_fin);
int partitionner(float *t, int i_debut, int i_fin);
void tri_rapide(float *t, int taille_t);

int main() {
    float tableau[TAILLE_MAX];
    int taille;
    printf("Saisir la taille du tableau puis ses valeurs :\n");
    taille = saisir_tableau(tableau);
    printf("Tableau avant tri :\n");
    afficher_tableau(tableau, taille);
    tri_rapide(tableau, taille);
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

void tri_rapide_rec(float *t, int i_debut, int i_fin) {
	int i_pivot;
	if (i_fin>i_debut) { 
		i_pivot = partitionner(t, i_debut, i_fin);
		tri_rapide_rec(t, i_debut, i_pivot - 1);
		tri_rapide_rec(t, i_pivot + 1, i_fin);
	}
}

int partitionner(float *t, int i_debut, int i_fin) {
	int i_pivot, i, j;
	float val; 
	i = i_debut;
	j = i_fin - 1;
	i_pivot = i_fin; 
	while (i<j) {
		while ( (i<j) && (t[i] <= t[i_pivot]) ) {
			i++;
		}
	while ( (i<j) && (t[j] > t[i_pivot]) ) {
		j--;
	}
	if (i<j) {
		val = t[j];
		t[j] = t[i];
		t[i] = val;
		i++;
		j--;
	}
	if (t[i] <= t[i_pivot]) {
		i++;
	}
	val = t[i_pivot];
	t[i_pivot] = t[i];
	t[i] = val;
	return i;
	}
}

void tri_rapide(float *t, int taille_t) {
	tri_rapide_rec(t, 0, taille_t - 1);
}
	


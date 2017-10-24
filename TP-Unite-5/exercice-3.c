#include <stdio.h>

#define MAX 40
#define TAILLE_TABLEAU 100

void initializeTab(int tab[], int taille) {
  int currentValue = 0;

  for (int i = 0; i < taille; i++) {
    tab[i] = currentValue;

    if (currentValue < MAX) {
      currentValue++;
    } else {
      currentValue = 0;
    }
  }
}

void affichageTableau(int tab[], int taille) {
  for(int i = 0; i < taille; i++) {
    printf("%d ", tab[i]);
  }
  printf("\n");
}

int main(void) {
  int tableau[TAILLE_TABLEAU];

  initializeTab(tableau, TAILLE_TABLEAU);
  affichageTableau(tableau, TAILLE_TABLEAU);

  return 0;
}

#include <stdio.h>

void copie(int tabSource[], int tabDestination[], int taille) {
  for(int i = 0; i < taille; i ++) {
    tabDestination[i] = tabSource[i];
  }
}

void affichageTableau(int tab[], int taille) {
  for(int i = 0; i < taille; i++) {
    printf("%d ", tab[i]);
  }
  printf("\n");
}

int main(void) {
  int tab1[10] = {2, 4, 9, 2, 4, 5, 2, 1, 9, 10};
  int tab2[10];

  copie(tab1, tab2, 10);

  affichageTableau(tab1, 10);
  affichageTableau(tab2, 10);

  return 0;
}

#include <stdio.h>

void affichageTableau(int tab[], int taille) {
  for(int i = 0; i < taille; i++) {
    printf("%d ", tab[i]);
  }
  printf("\n");
}

int main(void) {
  int tab1[] = {5, 4, 3, 2, 9, 7, 2};
  int tab2[] = {4, 2, 1, 9, 3, 3};

  affichageTableau(tab1, 7);
  affichageTableau(tab2, 6);

  return 0;
}

#include <stdio.h>

void affichageTableau(int tab[], int taille) {
  if (taille == 0) {
    printf("{}\n");
    return;
  }

  printf("{");

  for(int i = 0; i < taille - 1; i++) {
    printf("%d,", tab[i]);
  }

  printf("%d}\n", tab[taille - 1]);
}

int main(void) {
  int tab1[] = {4, 3, 9, 7, 3, 4, 5};
  int tab2[] = {1, 4, 12, 4, 89, 12, 32, 23, 7, 33, 3};

  affichageTableau(tab1, 7);
  affichageTableau(tab2, 11);

  return 0;
}

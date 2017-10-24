#include <stdio.h>

void affichageTableau(int tab[], int taille) {
  for(int i = 0; i < taille; i++) {
    printf("%d ", tab[i]);
  }
  printf("\n");
}

void inverserTableau(int tab[], int taille) {
  int temp;

  for(int i = 0; i < taille / 2; i++) {
    temp = tab[i];
    tab[i] = tab[taille - 1 - i];
    tab[taille - 1 - i] = temp;
  }
}

int main(void) {
  int tab[] = {4, 5, 2, 13, 8, 9, 12, 90};

  affichageTableau(tab, 8);
  inverserTableau(tab, 8);
  affichageTableau(tab, 8);

  return 0;
}

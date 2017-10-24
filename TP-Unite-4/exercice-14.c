#include <stdio.h>

int egaliteEtEchange(int *a, int *b) {
  if (*a == *b) {
    return 1;
  }

  int temp = *a;
  *a = *b;
  *b = temp;

  return 0;
}

int main(void) {
  int nombre1, nombre2;
  int egalite;

  printf("Veuillez entrer un premier nombre: ");
  scanf("%d", &nombre1);
  printf("Veuillez entrer un deuxième nombre: ");
  scanf("%d", &nombre2);

  egalite = egaliteEtEchange(&nombre1, &nombre2);

  printf("L'egalite: %d\n", egalite);
  printf("La valeur du nombre 1: %d\n", nombre1);
  printf("La valeur du nombre 2: %d\n", nombre2);

  return 0;
}

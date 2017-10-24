#include <stdio.h>

int sommeDuChiffre(int chiffre) {
  int somme = 0;
  int multiplicateur = 10;

  do {
    somme += chiffre % 10;
    chiffre = chiffre / 10;
  } while(chiffre != 0);

  return somme;
}

int main() {
  int chiffre;
  int somme;

  printf("Veuillez entrer un nombre: ");
  scanf("%d", &chiffre);

  somme = sommeDuChiffre(chiffre);

  printf("La somme est de %d\n", somme);

  return 0;
}

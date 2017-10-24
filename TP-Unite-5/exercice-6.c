#include <stdio.h>

int occurence(int tab[], int taille, int value) {
  int occurence = 0;

  for(int i = 0; i < taille; i++) {
    if (tab[i] == value) {
      occurence++;
    }
  }

  return occurence;
}

int main(void) {
  int tableau[] = {4, 2, 4, 8, 9, 1, 23, 23, 7, 8};

  printf("Occurence 1: %d\n", occurence(tableau, 10, 23));
  printf("Occurence 2: %d\n", occurence(tableau, 10, 9));
  printf("Occurence 2: %d\n", occurence(tableau, 10, 10));

  return 0;
}

#include <stdio.h>

int pgcd(int nombre1, int nombre2) {
  int max = nombre1 > nombre2 ? nombre1 : nombre2;
  int min = nombre1 < nombre2 ? nombre1 : nombre2;
  int reste = 0;

  while (max - min > 1) {
    reste = max - min;

    if (reste >= min) {
      max = reste;
    } else {
      min = reste;
    }
  }

  return reste;
}

int main(void) {
  printf("Le PDGC de 14 et 7 est: %d\n", pgcd(14, 7));
  printf("Le PDGC de 96 et 36 est: %d\n", pgcd(96, 36));
  printf("Le PDGC de 306 et 758 est: %d\n", pgcd(306, 758));
}

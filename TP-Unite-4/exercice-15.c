#include <stdio.h>

void demandeMaximumOccurence(int *maximum, int *occurence) {
  int nombreUtilisateur;
  *maximum = -1;
  *occurence = 0;

  scanf("%d", &nombreUtilisateur);

  while(nombreUtilisateur > 0) {
    if (nombreUtilisateur > *maximum) {
      *maximum = nombreUtilisateur;
      *occurence = 1;
    } else if (nombreUtilisateur == *maximum) {
      (*occurence)++;
    }

    scanf("%d", &nombreUtilisateur);
  }
}

int main(void) {
  int maximum, occurence;

  demandeMaximumOccurence(&maximum, &occurence);

  printf("Le nombre maximum est: %d\n", maximum);
  printf("Le nombre d'occurence du nombre: %d\n", occurence);

  return 0;
}

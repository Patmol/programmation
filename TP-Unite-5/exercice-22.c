#include <stdio.h>

void encodageVoyage(int voyages[], int *prixVoyageMinimum);
void affichageResultat(int voyages[], int prixVoyageMinimum);

int main(void) {
  int voyages[7] = {0};
  int prixVoyageMinimum = 0;

  encodageVoyage(voyages, &prixVoyageMinimum);
  affichageResultat(voyages, prixVoyageMinimum);

  return 0;
}

void encodageVoyage(int voyages[], int *prixVoyageMinimum) {
  int typeVoyage, prixInitial, prixFinale;

  printf("Notez le type suivi du prix de base et du prix obtenu: \n");
  scanf("%d %d %d", &typeVoyage, &prixInitial, &prixFinale);

  *prixVoyageMinimum = prixFinale;

  while (typeVoyage != 0) {
    if (prixFinale < *prixVoyageMinimum) {
      *prixVoyageMinimum = prixFinale;
    }

    voyages[typeVoyage - 1] += prixInitial - prixFinale;

    scanf("%d %d %d", &typeVoyage, &prixInitial, &prixFinale);
  }
}

void affichageResultat(int voyages[], int prixVoyageMinimum) {
  int typeVoyageReductionMaximale = 0;

  for (int i = 1; i < 7; i++) {
    if (voyages[i] > voyages[typeVoyageReductionMaximale]) {
      typeVoyageReductionMaximale = i;
    }
  }

  printf("Le type de voyage avec le plus de réductions obetnues est : %d\n", typeVoyageReductionMaximale + 1);
  printf("Le montant total de réductions pour le type %d est de %d€\n", typeVoyageReductionMaximale + 1, voyages[typeVoyageReductionMaximale]);
  printf("Le voyage le moins cher est de %d€\n", prixVoyageMinimum);
}

#include <stdio.h>
#include <stdbool.h>

#define KILOMETRES_MIN 55
#define VITESSE_MOY_MIN 12
#define DENIVELE_MIN 300

int main(void) {
  int jour, heures, minutes, denivelePositif, deniveleNegatif, deniveleCumule;
  int deniveleCumulePrecedent = 0, minTotale = 0;
  float kilometres, vitesseMoyenne, kilometresTotal = 0;
  bool minimumKilometre = true, denivele = false;

  printf("Encodage: \n");

  for(int i = 0; i < 30; i++) {
    scanf("%d %f %d %d %d %d", &jour, &kilometres, &heures, &minutes, &denivelePositif, &deniveleNegatif);

    deniveleCumule = denivelePositif - deniveleNegatif;

    if (jour != 0 && denivele == false && denivelePositif - deniveleNegatif > DENIVELE_MIN) {
      denivele = true;
    }

    deniveleCumulePrecedent = deniveleCumule;

    if (kilometres < KILOMETRES_MIN) {
      minimumKilometre = false;
    }

    kilometresTotal += kilometres;
    minTotale += (heures * 60) + minutes;
  }

  vitesseMoyenne = (kilometresTotal / minTotale) * 60.0;

  if (denivele && minimumKilometre && vitesseMoyenne > VITESSE_MOY_MIN) {
    printf("Vous êtes un bon rouleur !\n");
  }

  return 0;
}

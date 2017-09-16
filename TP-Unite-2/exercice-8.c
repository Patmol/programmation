#include <stdio.h>

#define MINUTES     60
#define HEURES      60 * MINUTES
#define JOURS       24 * HEURES

int main() {
    int secondes, minutes, heures, jours, total_secondes;

    printf("Veuillez entrer les secondes : ");
    scanf("%i", &secondes);
    printf("Veuillez entrer les minutes : ");
    scanf("%i", &minutes);
    printf("Veuillez entrer les heures : ");
    scanf("%i", &heures);
    printf("Veuillez entrer les jours : ");
    scanf("%i", &jours);

    total_secondes = secondes + minutes * MINUTES + heures * HEURES + jours * JOURS;

    printf("Le total en secondes est de : %i\n", total_secondes);

    return 0;
}
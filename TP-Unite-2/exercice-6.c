#include <stdio.h>

int main() {
    int dividende, diviseur;

    printf("Veuillez entrer le dividende : ");
    scanf("%i", &dividende);
    printf("Veuillez entrer le diviseur : ");
    scanf("%i", &diviseur);

    if (diviseur == 0) {
        printf("La division est impossible");
    } else {
        printf("Le resultat de la division entiere est %i\n", dividende / diviseur);
        printf("Le reste de la division est %i\n", dividende % diviseur);
    }

    return 0;
}
#include <stdio.h>

void affichageNombre(int nombre);

int main(void) {
    int nombre;

    printf("Votre nombre : ");
    scanf("%d", &nombre);

    affichageNombre(nombre);

    return 0;
}

void affichageNombre(int nombre) {
    char nombres[][20] = {"Zero", "Un", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf"};

    printf("%s\n", nombres[nombre]);
}
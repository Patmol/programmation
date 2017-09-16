#include <stdio.h>

#define NOMBRE_OR 1.61803398875

int main() {
    float largeur, longueur;

    printf("Veuillez entrer la largeur : ");
    scanf("%f", &largeur);

    longueur = largeur * NOMBRE_OR;

    printf("La longueur est de %f\n", longueur);

    return 0;
}
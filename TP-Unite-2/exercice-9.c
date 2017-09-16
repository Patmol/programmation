#include <stdio.h>

int main() {
    int dimension1, dimension2, dimension3;

    printf("Veuillez entrer une valeur pour la première dimension : ");
    scanf("%i", &dimension1);
    printf("Veuillez entrer une valeur pour la deuxième dimension : ");
    scanf("%i", &dimension2);
    printf("Veuillez entrer une valeur pour la troisième dimension : ");
    scanf("%i", &dimension3);

    if ((dimension1 + dimension2 > dimension3 && (dimension3 > dimension1 && dimension3 > dimension2)) ||
        (dimension1 + dimension3 > dimension2 && (dimension2 > dimension1 && dimension2 > dimension3)) ||
        (dimension2 + dimension3 > dimension1 && (dimension1 > dimension2 && dimension1 > dimension3))) {
            if (dimension1 == dimension2 &&
                dimension2 == dimension3) {
                    printf("Le triangle est equivalent\n");
                } else if (dimension1 == dimension2 ||
                    dimension2 == dimension3 ||
                    dimension1 == dimension3) {
                        printf("Le triangle est isocele\n");
                    }
                    else {
                        printf("Le triangle est scalene\n");
                    }
        } else {
            printf("Il ne s'agit pas d'un triangle\n");
        }

    return 0;
}
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Veuillez entrer un premier nombre : ");
    scanf("%i", &a);
    printf("Veuillez entrer un deuxième nombre : ");
    scanf("%i", &b);
    printf("Veuillez entrer un troisième nombre : ");
    scanf("%i", &c);

    if ((a < b && b < c) || (c < b && b < a)) {
        printf("La mediane est %i\n", b);
    } else if ((b < a && a < c) || (c < a && a < b)) {
        printf("La mediane est %i\n", a);
    } else if ((a < c && c < b) || (b < c && c < a)) {
        printf("La mediane est %i\n", c);
    }

    return 0;
}
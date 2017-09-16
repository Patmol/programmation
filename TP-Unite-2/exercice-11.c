#include <stdio.h>

#define NEERLANDAIS     'N'
#define FRANCAIS        'F'
#define ESPAGNOL        'E'
#define ANGLAIS         'A'

int main() {
    char langue, choix_utilisateur;
    int numero_telephone;

    printf("Veuillez entrer votre langue : ");
    scanf(" %c", &langue);

    if (langue == NEERLANDAIS) {
        do {
            printf("Vul alstublieft uw telefoonnummer in : ");
            scanf("%i", &numero_telephone);
            printf("Uw nummer is %i. Is dit correct? ", numero_telephone);
            scanf(" %c", &choix_utilisateur);
        } while (choix_utilisateur != 'o');
    } else if (langue == FRANCAIS) {
        do {
            printf("Veuillez entrer votre numéro de telephone : ");
            scanf("%i", &numero_telephone);
            printf("Votre numero est %i. Est-ce correct ? ", numero_telephone);
            scanf(" %c", &choix_utilisateur);
        } while (choix_utilisateur != 'o');
    } else if (langue == ESPAGNOL) {
        do {
            printf("Introduzca su número de teléfono : ");
            scanf("%i", &numero_telephone);
            printf("Su número es %i. ¿Es correcto? ", numero_telephone);
            scanf(" %c", &choix_utilisateur);
        } while (choix_utilisateur != 'o');
    } else if (langue == ANGLAIS) {
        do {
            printf("Please enter your phone number : ");
            scanf("%i", &numero_telephone);
            printf("Your number is %i. Is this correct? ", numero_telephone);
            scanf(" %c", &choix_utilisateur);
        } while (choix_utilisateur != 'o');
    } else {
        printf("La langue choisie n'est pas disponible.\n");
    }

    return 0;
}
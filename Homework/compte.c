#include <stdio.h>

#define MAX_COUPS 5
#define MAX_NOMBRE 1000
#define MAX_NOMBRE_UTILISATEUR 10

int main(void) {
    srand(time(NULL));
    int nombre_but = rand()%MAX_NOMBRE;
    int nombre1 = rand()%MAX_NOMBRE_UTILISATEUR;
    int nombre2 = rand()%MAX_NOMBRE_UTILISATEUR;
    int nombre3 = rand()%MAX_NOMBRE_UTILISATEUR;
    int nombreUtilisateur1, nombreUtilisateur2, nombreCoups = 0;
    float resultatUtilisateur;
    char operationUtilisateur;

    printf("Nombre à attenidre: %d\n", nombre_but);
    printf("Nombre à utiliser: %d %d %d\n", nombre1, nombre2, nombre3);    

    scanf("%d %c %d", &nombreUtilisateur1, &operationUtilisateur, &nombreUtilisateur2);

    switch(operationUtilisateur) {
        case '+':
            resultatUtilisateur = nombreUtilisateur1 + nombreUtilisateur2;
            break;
        case '-':
            resultatUtilisateur = nombreUtilisateur1 - nombreUtilisateur2;
            break;
        case '*':
            resultatUtilisateur = nombreUtilisateur1 * nombreUtilisateur2;
            break;
        case '/':
            resultatUtilisateur = (float)nombreUtilisateur1 / nombreUtilisateur2;
            break;
    }
    
    printf("Score actuel: %.0f\n", resultatUtilisateur);

    while (nombreCoups < 5 && resultatUtilisateur != nombre_but) {
        printf("Nouveau calcul: %.0f", resultatUtilisateur);
        scanf("%c %d", &operationUtilisateur, &nombreUtilisateur1);
        
        switch(operationUtilisateur) {
            case '+':
                resultatUtilisateur += nombreUtilisateur1;
                break;
            case '-':
                resultatUtilisateur -= nombreUtilisateur1;
                break;
            case '*':
                resultatUtilisateur *= nombreUtilisateur1;
                break;
            case '/':
                resultatUtilisateur /= (float)nombreUtilisateur1;
                break;
        }

        if (resultatUtilisateur != nombre_but) {
            printf("Score actuel: %.0f\n", resultatUtilisateur);
        }

        nombreCoups++;
    }

    if (resultatUtilisateur != nombre_but) {
        printf("Vous avez trouvé un nombre qui est à %.0f du nombre choisi.\n", nombre_but - resultatUtilisateur);
    } else {
        printf("Bravo, vous avez atteint %.0f !\n", resultatUtilisateur);
    }
}
#include <stdio.h>

#define MAX_CLIENTS 1000
#define NOMBRE_TRAITEMENTS 4
#define PRIX_CLASSIQUE 10
#define PRIX_BRUSHING 15
#define PRIX_COUPE 29
#define PRIX_COLORANT 35

typedef struct client {
    int id;
    int traitements[NOMBRE_TRAITEMENTS];
} Client;

void encodage(int traitements[], Client clients[], int *nombreClients);
void affichage(int traitements[], Client clients[], int nombreClients);

int main(void) {
    int nombreClients = 0;
    int traitements[NOMBRE_TRAITEMENTS];
    Client clients[MAX_CLIENTS];

    encodage(traitements, clients, &nombreClients);
    affichage(traitements, clients, nombreClients);

    return 0;
}

void encodage(int traitements[], Client clients[], int *nombreClients) {
    int idClient, indexClient = -1;
    char typeTraitement;

    for (int i = 0; i < NOMBRE_TRAITEMENTS; i++) {
        traitements[i] = 0;
    }

    scanf("%d", &idClient);

    while(idClient != -1) {
        scanf("%c", &typeTraitement);

        switch(typeTraitement) {
            case 'A':
                traitements[0]++;
                break;
            case 'B':
                traitements[1]++;
                break;
            case 'C':
                traitements[2]++;
                break;
            case 'D':
                traitements[3]++;
                break;
        }

        if(idClient != 0) {
            for (int i = 0; i < *nombreClients && indexClient == -1; i++) {
                if (clients[i].id == idClient) {
                    indexClient = i;
                }
            }

            if (indexClient == -1) {
                clients[*nombreClients].id = idClient;
                
                for (int i = 0; i < NOMBRE_TRAITEMENTS; i++)  {
                    clients[*nombreClients].traitements[i] = 0;
                }

                indexClient = *nombreClients;
                (*nombreClients)++;
            }

            switch(typeTraitement) {
                case 'A':
                    clients[indexClient].traitements[0]++;
                    break;
                case 'B':
                    clients[indexClient].traitements[1]++;
                    break;
                case 'C':
                    clients[indexClient].traitements[2]++;
                    break;
                case 'D':
                    clients[indexClient].traitements[3]++;
                    break;
            }

            indexClient = -1;
        }

        scanf("%d", &idClient);
    }
}

void affichage(int traitements[], Client clients[], int nombreClients) {
    float remboursementClient;

    printf("\n");
    printf("%d soins classiques: %.1f EUR.\n", traitements[0], traitements[0] * (float)PRIX_CLASSIQUE);
    printf("%d brushings: %.1f EUR.\n", traitements[1], traitements[1] * (float)PRIX_BRUSHING);
    printf("%d coupes brushing: %.1f EUR.\n", traitements[2], traitements[2] * (float)PRIX_COUPE);
    printf("%d shampoings colorant: %.1f EUR.\n", traitements[3], traitements[3] * (float)PRIX_COLORANT);
    printf("\n");

    for (int i = 0; i < nombreClients; i++) {
        remboursementClient = (((clients[i].traitements[0] * PRIX_CLASSIQUE) / 100.0) * 5) + 
            (((clients[i].traitements[1] * PRIX_BRUSHING) / 100.0) * 7) + 
            (((clients[i].traitements[2] * PRIX_COUPE) / 100.0) * 10) + 
            (((clients[i].traitements[3] * PRIX_COLORANT) / 100.0) * 15);

        printf("Il faut rembourser %.2f au client %d\n", remboursementClient, clients[i].id);
    }
}
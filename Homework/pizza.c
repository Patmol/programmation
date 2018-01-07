#include <stdio.h>

#define NOMBRE_PIZZA 3
#define PRIX_PIZZA_MARG 3
#define PRIX_PIZZA_FROM 4
#define PRIX_PIZZA_AI 2.5
#define PRIX_PIZZA 5
#define REDUCTION_1 5
#define REDUCTION_2 10

void encodagePizza(int pizzas[NOMBRE_PIZZA], float beneficesPizzas[NOMBRE_PIZZA], int *nombreClient);
void affichageGraphe(int pizzas[NOMBRE_PIZZA]);
void affichageResultat(int pizzas[NOMBRE_PIZZA], float beneficesPizzas[NOMBRE_PIZZA], int nombreClient);

int main(void) {
    int pizzas[NOMBRE_PIZZA];
    int nombreClient = 0;
    float beneficesPizzas[NOMBRE_PIZZA];

    encodagePizza(pizzas, beneficesPizzas, &nombreClient);
    affichageResultat(pizzas, beneficesPizzas, nombreClient);

    return 0;
}

void encodagePizza(int pizzas[NOMBRE_PIZZA], float beneficesPizzas[NOMBRE_PIZZA], int *nombreClient) {
    // Variable utilisées pour l'encodage
    int nombrePizzaMarg, nombrePizzaFrom, nombrePizzaAi;
    int totalPrix, totalPizza;

    // Initialization des tableaux
    for (int i = 0; i < NOMBRE_PIZZA; i++) {
        pizzas[i] = 0;
        beneficesPizzas[i] = 0;
    }

    printf("Donnez la commande : \n");
    scanf("%d %d %d", &nombrePizzaMarg, &nombrePizzaFrom, &nombrePizzaAi);

    while (nombrePizzaMarg != -1) {
        (*nombreClient)++;

        // Calcul de la somme à payer
        totalPizza = nombrePizzaMarg + nombrePizzaFrom + nombrePizzaAi;
        totalPrix = totalPizza * PRIX_PIZZA;

        // Calcul de la réduction
        // Attention à l'ordre des IF
        if (totalPizza >= REDUCTION_2)  {
            totalPrix = totalPrix - ((float)totalPrix / 100 * REDUCTION_2);
        } else if (totalPizza >= REDUCTION_1) {
            totalPrix = totalPrix - ((float)totalPrix / 100 * REDUCTION_1);
        }

        // Sauvegarde des pizza achetées
        pizzas[0] += nombrePizzaMarg;
        pizzas[1] += nombrePizzaFrom;
        pizzas[2] += nombrePizzaAi;        

        // Affichage du prix à l'utilisateur
        printf("Le client doit payer %.2d euros\n", totalPrix);

        printf("Donnez la commande : \n");
        scanf("%d %d %d", &nombrePizzaMarg, &nombrePizzaFrom, &nombrePizzaAi);
    }

    // Calcul des bénéfices par pizza
    beneficesPizzas[0] += ((pizzas[0] * PRIX_PIZZA) - (PRIX_PIZZA_MARG * pizzas[0])); 
    beneficesPizzas[1] += ((pizzas[1] * PRIX_PIZZA) - (PRIX_PIZZA_FROM * pizzas[1]));
    beneficesPizzas[2] += ((pizzas[2] * PRIX_PIZZA) - (PRIX_PIZZA_AI * pizzas[2]));
}

void affichageGraphe(int pizzas[NOMBRE_PIZZA]) {
    int nombreEtoile = 17;
    int pourcentageMarg, pourcentageFrom, pourcentageAi;
    int etoileMarg, etoileFrom, etoileAi;
    int totalPizza = 0;

    for (int i = 0; i < NOMBRE_PIZZA; i++) {
        totalPizza += pizzas[i];
    }

    // Vérifier si le nombre de pizza n'est pas égale à 0 !
    pourcentageMarg = (((float)pizzas[0] / totalPizza) * 100);
    pourcentageFrom = (((float)pizzas[1] / totalPizza) * 100);
    // Le pourcentage de la pizza ai est calculé différement pour être sur d'avoir 100% 
    // Risque d'erreur de précision aussi non
    pourcentageAi = 100 - pourcentageMarg - pourcentageFrom;

    etoileMarg = ((float)pourcentageMarg / 100) * nombreEtoile;
    etoileFrom = ((float)pourcentageFrom / 100) * nombreEtoile;
    etoileAi = ((float)pourcentageAi / 100) * nombreEtoile;

    printf("\t\t0%%\t50%%\t100%%\n");
    printf("\t\t|\t|\t|\n");

    printf("Margherita\t|");
    for(int i = 0; i < etoileMarg; i++) {
        printf("*");
    }
    printf("\n");

    printf("4 fromages\t|");
    for(int i = 0; i < etoileFrom; i++) {
        printf("*");
    }
    printf("\n");

    printf("Funghi\t\t|");
    for(int i = 0; i < etoileAi; i++) {
        printf("*");
    }
    printf("\n");

    printf("Pizzas vendus: %d\n\n", totalPizza);
}

void affichageResultat(int pizzas[NOMBRE_PIZZA], float beneficesPizzas[NOMBRE_PIZZA], int nombreClient) {
    float totalBenefices = 0;
    int totalVente = 0;
    int totalPizza = 0;

    affichageGraphe(pizzas);

    printf("Benefices sur les pizzas margherita: %.2f euros\n", beneficesPizzas[0]);
    printf("Benefices sur les pizzas 4 fromages: %.2f euros\n", beneficesPizzas[1]);
    printf("Benefices sur les pizzas funghi: %.2f euros\n", beneficesPizzas[2]);

    for (int i = 0; i < NOMBRE_PIZZA; i++) {
        totalBenefices += beneficesPizzas[i];
        totalPizza += pizzas[i];
        totalVente += pizzas[i] * PRIX_PIZZA;
    }

    printf("Benefices totals: %.2f\n\n", totalBenefices);
    printf("Nombre de clients: %d\n", nombreClient);
    printf("Nombre de pizza en moyenne par client: %d\n", totalPizza / nombreClient);
    printf("Depense moyenne par client: %.2f", (float)totalVente / nombreClient);
}
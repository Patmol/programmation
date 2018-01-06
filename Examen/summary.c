/***************************************/
/*  Résumé du cours de programmation 1 */
/***************************************/

/*************** INCLUDE ***************/
/* Ajout des includes */
/* stdio.h permet de faire appel aux fonctions d'écriture */
/* ex. : printf */
#include <stdio.h>
/* stdbool.h permet de travailler avec des variables bool (vrai/faux) */
#include <stdbool.h>
/* stdlib.h permet d'obtenir une valeur absolue via abs() */
#include <stdlib.h>
/* string.h permet de travailler avec les chaines de caractères (comparaison) */
#include <string.h>

/*************** DEFINE ***************/
/* #define permet de lier un mot à une valeur.
   #define MAX_NANARS 100 : MAX_NANARS sera remplacée par la valeur 100 lors du préprocessing
   /!\ Il n'y a pas de = pour l'assignation ou de ; à la fin de la ligne /!\ */
#define MAX_ELEMENTS 100
#define MAX_TITRE 50

/************** STRUCTURE *************/
/* Création d'une structure
   Ne pas oublier le ; à la fin de la déclaration de la structure */
struct film {
    /* Ajout des propriétés qui composent la structure */
    char titre[MAX_TITRE];
    int duree;
    int note;
};
/* Si on veut utiliser la structure, on doit utiliser le type complet
  'struct film' et non pas juste 'film' */
/* On peut créer un alias à ce type via le mot clé 'typedef struct film UnFilm' 
   UnFilm étant le type de la variable */
struct maison {
    int pieces;
    double prix;
};
typedef struct maison UneMaison;
/* Il y a la possibilité de réaliser ces deux actions en une seule */
typedef struct voiture {
    int anneeConstruction;
    int puissance;
    int nombrePorte;
} UneVoiture;

/* On doit ensuite déclarer nos fonctions (ou alors juste la signature de celles-ci) */
/************** SIGNAURE **************/
void constructeur(UneMaison* maison, int pieces, double prix);
void affichageMaison(UneMaison maison);
void lire_tableau(int a[MAX_ELEMENTS]);
void compter(int a[MAX_ELEMENTS], float moyenne, int *dessous, int *max);

/**************** MAIN ****************/
/* Le main est le point d'entrée du programme, celui-ci est obligatoire
   Sa signature ne peut pas être différente */
int main(void) {
    /* Le contenu principale de la fonction main sera la déclaration des
       variables ainsi que l'appels des fonctions (Sauf dans les programmes court) */

    /************** VARIABLES *************/
    /* Déclaration d'un tableau sous le format : typeVariable nomTableau[TAILLE] */
    int monTableau[8];
    /* Déclaration d'une variable de type réelle */
    float moyenne;
    /* Déclaration d'une variable de type entière */
    int monEntier1, monEntier2;
    /* Déclaration d'une chaine de caractère - string */
    char texte[20];
    
    /******* APPELLES DES FONCTIONS *******/
    /* Lors du passage d'un tableau en paramètre d'une fonction, celui-ci est 
       automatiquement passé en tant que référence. */
    lire_tableau(monTableau);

    /* Lorsque notre fonction attend un paramètre en tant que pointeur (noté via * dans la signature),
       il faut passer la variable en tant que référence et non en tant que valeur. Utilisation du & pour le passage par référence. 
       Le passage par référence permet de modifier la variable dans la fonction et non pas d'en envoyer une copie*/
    compter(monTableau, moyenne, &monEntier1, &monEntier2);

    /* Ecriture vian la fonction printf 
       Pour ajouter des variables dans notre texte, on utilise un placeholder 
       %d ou %i pour un int 
       %f pour un float ou un double 
       %c pour un char
       %s pour une chaine de caractère */
    /* /!\ Ne pas oublier le \n à la fin si on veut un retour à la ligne */
    printf("Mon entier 1 est %d et mon float est %f\n", monEntier1, moyenne);
    /* /!\ J'utilise la variable texte en tant qu'exemple mais celle-ci n'est pas initialisée -> Risque d'erreur /!\ */
    printf("Mon texte est : %s \n", texte);

    /* /!\ Ne pas oublier le return de la fonction main /!\
       Par défaut, on retourne 0 pour indiquer à l'OS que l'execution du programme s'est passée correctement */
}

/************** FONCTIONS *************/
/* Le tableau est passé par référence de manière implicite */
void lire_tableau(int monTableau[MAX_ELEMENTS]) {
    int x, y, z;

    /* Initialisation des valeurs du tableau */
    /* Déclaration d'une variable i temporaire pour boucler sur le tableau */
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        /* On accède à un élément du tableau via [index] */
        /* Même si le tableau est passé en référence, comme on accède à un élément de celui-ci
           nous n'avons aucune syntaxe particulière à utiliser */
        monTableau[i] = 0;
    }

    /* Lecture d'une entrée de l'utilisateur via la fonction scanf
       Le premier paramètre est une chaine de caractère qui est le placeholder du type 
       de la variable qu'on va lire.
       Le second paramètre de la fonction scanf doit être une référence vers la variable 
       dans laquelle on va stocker notre valeur. */
    scanf("%d", &x);
    /* Le scanf peut lire plusieurs valeurs en même temps */
    scanf("%d %d", &y, &z);
}

/* Les paramètres dessous et max sont des pointeurs, ils sont passés par référence, il faut donc faire attention
   lors de l'utilisation de ceux-ci */
void compter(int a[MAX_ELEMENTS], float moyenne, int *dessous, int *max) {
    /* Pour accéder à la valeur d'une variable passée en référence, il faut utiliser un * devant le nom de celle-ci */
    *dessous = 0;
    *max = 0;

    /* /!\ Lors d'une division de deux entier, le résultat est un entier, si on veut un décimal, il faut caster un des
       deux nombres /!\*/
    moyenne = (float)(*dessous) / *max;
}

/* Lorsqu'on veut recevoir une structure en tant que paramètre d'une fonction,
   on doit utiliser un pointeur */
void constructeur(UneMaison* maison, int pieces, double prix) {
    /* Lorsqu'on veut accéder à une structure qui est un pointeur vers celle-ci, il faut utiliser une notation un peu particulière */
    maison->prix = prix;
    /* Ou cette écriture */
    (*maison).pieces = pieces;
}

void affichageMaison(UneMaison maison) {
    /* Dans les cas ou la structure est passé simplement en tant que valeur, l'accès au propriétés de celle-ci
       se fait via le . */
    printf("Pièces: %d", maison.pieces);
}
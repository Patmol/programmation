#include <stdio.h>
#define NBCOTES 21

// En-tête des fonctions du programme
void lire_suite(int a[NBCOTES]);
void calculer_moyenne_et_max(int cotes[NBCOTES], float *moyenne, int *max);
void compter(int cotes[NBCOTES], float moy, int *dessous, int *dessus);

int main(void) {
  // Tableau du nombre d'occurence des cotes des élèves
  // Il s'agit d'un tableau allant de 0 à 20
  // Lorsqu'on rencontre une cote, on incrémente la valeur à l'index de cette
  //    cotes
  // Exemple: Si on rencontre la cote 13, on incrémente la valeur à l'indice 13
  //    pour indiquer qu'on a rencontré une fois de plus la cote 13
  int cotes[NBCOTES];
  // Moyennes des cotes des élèves
  float moyenne;
  // Cote maximale
  int cote_max;
  // Nombre de cotes en dessous et au dessus de la moyenne
  int dessous, dessus;

  // Lecture des cotes entrées par l'utilisateur
  lire_suite(cotes);
  // Calcul de la moyenne et du maximum
  calculer_moyenne_et_max(cotes, &moyenne, &cote_max);
  // Nombre de cote en dessous et au dessus
  compter(cotes, moyenne, &dessous, &dessus);
  // Affichage des résultats
  printf("Moyenne : %.2f Cote maximale : %d Dessous %d Dessus : %d\n",
    moyenne, cote_max, dessous, dessus);

  return 0;
}

// Lecture des cotes entrées par l'utilisateur
// cotes : Paramètre de sortie, le tableau est passé par référence (implicite)
void lire_suite(int a[NBCOTES]) {
  // Cote que l'utilisateur vient de rentrer
  int x;

  // Boucle qui initialise les valeurs du tableau à 0
  // Déclaration de la variable d'incrémentation (i) dans le for directement
  for (int i = 0; i < NBCOTES; i++) {
    a[i] = 0;
  }

  // Lecture de la cotes
  scanf("%d", &x);

  // Vérification si la valeur entrée n'est pas notre sentinelle
  // Et si celle-ci est une valeur possible (entre nos bornes du tableau
  //    comprise entre 0 et 20 - taille du tableau - 1)
  // Si la valeur est incorrecte, on n'arrête la lecture
  while (x != -1 && (x >= 0 && x <= 20)) {
    // Incrémentation de 1 de la valeur à l'index de notre cotes
    a[x]++; // Version simplifié de a[x] = a[x] + 1;
    // Lecture de la cote suivante
    scanf("%d", &x);
  }
}

// Calcul de la moyenne et du maximum
// cotes : Paramètre d'entrée, le tableau des cotes (par référence)
// moy : Paramètre de sortie, la moyenne des cotes (par référence)
// max : Paramètre de sortie, la cote maximale (par référence)
void calculer_moyenne_et_max(int cotes[NBCOTES], float *moy, int *max) {
  int nb = 0;     // Nombre de cotes
  int somme = 0;  // Somme totale des cotes

  // Calcul de la somme total des cotes, du nombre de cote et recherche du max
  for (int i = 0; i < NBCOTES; i++) {
    // La somme est la somme des valeurs de nos indices (i) - et donc de nos
    //    cotes - multiplié par le nombre de fois que celles-ci sont apparues
    //    dans l'encodage
    somme += cotes[i] * i;
    // Le nombre de cotes est la somme totale des valeurs de notre tableau
    // Exemple : Si nous avons 5 à l'indice 10 et 2 à l'indice 14, cela
    //    représente 5 + 2 = 7 cotes entrées par l'utilisateur
    nb += cotes[i];

    // Le calcul du maximum se fait dans la même boucle. Celui-ci est trouvé
    //    en regardant si la valeur du tableau à l'indice i est différente de 0,
    //    si c'est le cas, cela signifie qu'une côte à été rentrée pour cette
    //    valeur. Etant donnée que nous parcourons le tableau de 0 à 20, si nous
    //    avons des valeurs, pour l'indice en cours, c'est obligatoirement la
    //    note la plus élevée
    if (cotes[i] != 0) {
      *max = i;
    }
  }

  // Calcul de la moyenne
  // Casting d'une des valeurs de la division afin d'avoir une division de
  //    nombres réelles
  *moy = (float)somme / nb;
}

// On compte le nombre de valeur en dessous et au dessus de la moyenne
// cotes : Paramètre d'entrée, le tableau des cotes (par référence)
// moy : Paramètre d'entrée, la moyenne des cotes (par valeur)
// dessous : Nombre de cotes en dessous de la moyenne (par référence)
// dessus : Nombre de cotes au dessus de la moyenne (par référence)
void compter(int cotes[NBCOTES], float moy, int *dessous, int *dessus) {
  *dessous = 0;
  *dessus = 0;

  for (int i = 0; i < NBCOTES; i++) {
    // Pour calculer le nombre de cotes en dessous ou au dessus de la moyenne,
    //    nous regardons notre indice (qui est en réalité la cote de l'élève)
    //    si l'indice est inférieur à la moyenne, on addition le nombre de fois
    //    que l'indice apparait à dessous et si l'indice est supérieur, nous
    //    additionnons le nombre de fois à dessus
    if (i >= moy) {
      *dessus += cotes[i]; // dessus = dessus + cotes[i];
    } else {
      *dessous += cotes[i]; // dessous = dessous + cotes[i];
    }
  }
}

#include <stdio.h>

#define BORD_TOILE 12
#define DEMI_BORD_TOILE BORD_TOILE / 2
#define CENTIMETRE_DANS_METRE 100
#define CM_CARRE_DANS_M_CARRE 10000

int main() {
  // Variable utilisées pour récupérer les inputs de l'utilisateur
  float longueur_toile,
        largeur_toile,
        cout_bois,
        cout_toile;

  // Variables utilisées pour les calculs
  float total_bois_metre,
        surface_total_toile_metre_carre,
        cout_total_bois,
        cout_total_toile,
        cout_total_materiaux;

  // Demande des informations à l'utilisateur
  printf("Veuillez entrer la longeur de la toile :\n");
  scanf("%f", &longueur_toile);
  printf("Veuillez entrer la largeur de la toile :\n");
  scanf("%f", &largeur_toile);
  printf("Veuillez entrer le cout au metre du bois :\n");
  scanf("%f", &cout_bois);
  printf("Veuillez entrer le cout au metre carre de la toile :\n");
  scanf("%f", &cout_toile);

  // Calcul de la longueur totale de bois requise en metre
  total_bois_metre = ((longueur_toile + largeur_toile) * 2)
    / CENTIMETRE_DANS_METRE;
  // Calcul du cout total du bois
  cout_total_bois = total_bois_metre * cout_bois;
  // Calcul de la surface de la toile en metre carre
  surface_total_toile_metre_carre = ((longueur_toile + DEMI_BORD_TOILE) *
    (largeur_toile + DEMI_BORD_TOILE)) / CM_CARRE_DANS_M_CARRE;
  // Calcul du cout de la toile
  cout_total_toile = surface_total_toile_metre_carre * cout_toile;
  // Calcul du cout total des materiaux
  cout_total_materiaux = cout_total_toile + cout_total_bois;

  // Affichage des résultats
  printf("Pour une peinture de %.1f cm de longeur et une largeur de %.1f, ",
    longueur_toile, largeur_toile);
  printf("vous devriez acheter %.2f cm de bois.\n\n",
    total_bois_metre * CENTIMETRE_DANS_METRE);

  printf("La toile devra avoir une longeur de %.1f cm ",
    longueur_toile + DEMI_BORD_TOILE);
  printf("et une largeur de %.1f cm.\n\n",
    largeur_toile + DEMI_BORD_TOILE);

  printf("Etant donne que le prix du bois est de %.2f euro ", cout_bois);
  printf("par metre courant, et que la toile coute %.2f ", cout_toile);
  printf("par metre carre:\n");
  printf("Le bois coutera %.2f euro.\n", cout_total_bois);
  printf("La toile coutera %.2f euro.\n", cout_total_toile);
  printf("Le prix total des materiaux sera %.2f euro.\n", cout_total_materiaux);

  return 0;
}

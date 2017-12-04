#include <stdio.h>
#include <stdbool.h>
// Utiliser pour la valeur absolue (abs())
#include <stdlib.h>
// Utiliser pour les fonctions sur les chaines de caractères
#include <string.h>

#define LONG_MAX_TITRE 100
#define MAX_NANARS 100
#define NOTE_NAVET 3
#define NOTE_MAUVAIS 6
#define NOTE_OEUVRE 8
#define NOTE_CULTE 10

typedef struct film {
  char titre[LONG_MAX_TITRE];
  int duree;
  int note;
  int idClient;
} Film;

void constructeur(Film* nanar, char titre[LONG_MAX_TITRE], int duree, int note);
void encodage(Film nanars[MAX_NANARS], int *nbrNanars);
void emprunt(Film nanars[MAX_NANARS], int nbrNanars);

int main(void) {
  Film nanars[MAX_NANARS];
  int nbrNanars;

  encodage(nanars, &nbrNanars);
  emprunt(nanars, nbrNanars);

  return 0;
}

void constructeur(Film* nanar, char titre[LONG_MAX_TITRE], int duree, int note) {
  strcpy(nanar->titre, titre);
  nanar->duree = duree;
  nanar->note = note;
  nanar->idClient = 0;

  if (nanar->note <= NOTE_NAVET) {
    printf("C'est un navet\n");
  } else if (nanar->note <= NOTE_MAUVAIS) {
    printf("C'est un mauvais nanar\n");
  } else if (nanar->note <= NOTE_OEUVRE) {
    printf("C'est une oeuvre nanarde\n");
  } else {
    printf("C'est un nanar culte\n");
  }
}

void encodage(Film nanars[MAX_NANARS], int *nbrNanars) {
  char titre[LONG_MAX_TITRE];
  int duree, note;
  printf("Combien de nanar voulez-vous encoder ?\n");
  scanf("%d", nbrNanars);

  for (int i = 0; i < *nbrNanars; i++) {
    scanf("%s", titre);
    scanf("%d", &duree);
    scanf("%d", &note);
    constructeur(&nanars[i], titre, duree, note);
  }
}

void emprunt(Film nanars[MAX_NANARS], int nbrNanars) {
  int idClient;

  do {
    int indexNanar;
    int differenceDuree = 1000;
    char choixEmpruntAlternatif;
    char titreEmprunt[LONG_MAX_TITRE];

    printf("Identifiant du client: \n");
    scanf("%d", &idClient);

    if (idClient != -1) {
      printf("Titre du nanar à emprunter: \n");
      scanf("%s", titreEmprunt);

      for (int i = 0; i < nbrNanars; i++) {
        if(strcmp(nanars[i].titre, titreEmprunt) == 0) {
          indexNanar = i;
        }
      }

      if (nanars[indexNanar].idClient == 0) {
        nanars[indexNanar].idClient = idClient;
        printf("ok\n");
      } else {
        printf("Ce nanar est déjà loué par le client %d\n", nanars[indexNanar].idClient);

        for (int i = 0; i < nbrNanars; i++) {
          if (abs(nanars[indexNanar].duree - nanars[i].duree) < differenceDuree &&
            nanars[i].idClient == 0) {
            differenceDuree = abs(nanars[indexNanar].duree - nanars[i].duree);
            indexNanar = i;
          }
        }

        printf("Voulez-vous plutôt emprunter %s ?\n", nanars[indexNanar].titre);
        scanf(" %c", &choixEmpruntAlternatif);

        if (choixEmpruntAlternatif == 'o') {
          nanars[indexNanar].idClient = idClient;
        }
      }
    } else {
      printf("Au revoir !\n");
    }
  } while (idClient != -1);
}

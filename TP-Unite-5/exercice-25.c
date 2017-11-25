#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAILLE_NOM 200

typedef struct {
  char nom[MAX_TAILLE_NOM];
  int numeroTelephone;
} Personne;

void initialisePersonne(char nom[], int numeroTelephone, Personne* p);
bool numeroIdentiqueNomsDifferent(Personne personnes[], int taille);

int main(void) {
  Personne personnes[20];
  initialisePersonne("Evrard", 63218967, &personnes[0]);
  initialisePersonne("Demars", 473353817, &personnes[1]);
  initialisePersonne("Bernardy", 63218967, &personnes[2]);

  if (numeroIdentiqueNomsDifferent(personnes, 3)) {
    printf("Des personnes possèdes le même numéro avec des noms différents\n");
  } else {
    printf("Aucune personne ne possède le même numéro avec des noms dfférents\n");
  }

  return 0;
}

void initialisePersonne(char nom[], int numeroTelephone, Personne* p) {
  strcpy(p->nom, nom);
  p->numeroTelephone = numeroTelephone;
}

bool numeroIdentiqueNomsDifferent(Personne personnes[], int taille) {
  for (int i = 0; i < taille; i++) {
    for (int j = i + 1; j < taille; j++) {
      if (strcmp(personnes[i].nom, personnes[j].nom) != 0 && personnes[i].numeroTelephone == personnes[j].numeroTelephone) {
        return true;
      }
    }
  }

  return false;
}

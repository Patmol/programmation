#include <stdio.h>
#include <stdbool.h>

#define TAILLE_TABLEAU 100
#define TAILLE_TABLEAU_LETTRES 26
#define MAX_ERREURS 6

void jeu(char mot[]);
bool afficageMot(char mot[], char lettres[], char lettre);
void affichageMotFinale(char mot[]);
void initializeTableauLettres(char lettres[]);
bool verificationValiditeLettre(char lettres[], char lettre);
bool verificationPresenceLettre(char mot[], char lettre);

int main(void) {
  char mot[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r', '\0'};

  jeu(mot);

  return 0;
}

void jeu(char mot[]) {
  char lettres[TAILLE_TABLEAU_LETTRES];
  char lettreUtilisateur;
  int nombreErreur = 0;
  bool motTrouve = false;

  initializeTableauLettres(lettres);

  while (motTrouve == false && nombreErreur < MAX_ERREURS) {
    printf("Veuillez entrer une lettre: ");
    scanf(" %c", &lettreUtilisateur);

    if(!verificationValiditeLettre(lettres, lettreUtilisateur) || !verificationPresenceLettre(mot, lettreUtilisateur)) {
      nombreErreur++;
    }

    motTrouve = afficageMot(mot, lettres, lettreUtilisateur);

    if (MAX_ERREURS - nombreErreur == 0) {
      printf("Il vous reste %d tentative\n", MAX_ERREURS - nombreErreur);
    }
    else {
      printf("Il vous reste %d tentatives\n", MAX_ERREURS - nombreErreur);
    }
  }

  if (motTrouve) {
    printf("Le mot a été trouvé. Félicitations !\n");
  } else {
    printf("Dommage, vous n'avez pas trouvé le mot: ");
    affichageMotFinale(mot);
    printf("\n");
  }
}

bool verificationValiditeLettre(char lettres[], char lettre) {
  for(int i = 0; i < TAILLE_TABLEAU_LETTRES; i++) {
    if (lettres[i] == '\0') {
      lettres[i] = lettre;
      return true;
    } else if (lettres[i] == lettre) {
      return false;
    }
  }

  return false;
}

bool verificationPresenceLettre(char mot[], char lettre) {
  char currentLettre;

  for(int i = 0; i < TAILLE_TABLEAU && mot[i] != '\0'; i++) {
    if (mot[i] == lettre) {
      return true;
    }
  }

  return false;
}

bool afficageMot(char mot[], char lettres[], char lettre) {
  bool motTrouve = true;
  bool lettreTrouve = false;

  for (int i = 0; i < TAILLE_TABLEAU && mot[i] != '\0'; i++) {
    for (int j = 0; j < TAILLE_TABLEAU_LETTRES && lettres[j] != '\0'; j++) {
      if (mot[i] == lettres[j]) {
        lettreTrouve = true;
        break;
      }
    }

    if (lettreTrouve) {
      printf("%c", mot[i]);
      lettreTrouve = false;
    } else {
      printf("*");
      motTrouve = false;
      lettreTrouve = false;
    }
  }

  printf("\n");

  return motTrouve;
}

void affichageMotFinale(char mot[]) {
  for(int i = 0; i < TAILLE_TABLEAU; i++) {
    if(mot[i] == '\0') {
      return;
    }

    printf("%c", mot[i]);
  }
}

void initializeTableauLettres(char lettres[]) {
  for (int i = 0; i < TAILLE_TABLEAU_LETTRES; i++) {
    lettres[i] = '\0';
  }
}

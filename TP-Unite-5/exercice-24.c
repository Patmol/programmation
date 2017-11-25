#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NOMBRE_MAISONS 10
#define MAX_MAISONS_AGENCE 100
#define MAX_CLIENTS_AGENCE 200

typedef struct client Client;
struct client {
  int id;
  int compte;
  int nbMaisons;
  int maisons[MAX_NOMBRE_MAISONS];
};

typedef struct maison Maison;
struct maison {
  int id;
  int prix;
  int nbChambre;
  bool vendue;
};

typedef struct agence Agence;
struct agence {
  int nbMaisons;
  int nbClients;
  Client* clients[MAX_CLIENTS_AGENCE];
  Maison* maisons[MAX_MAISONS_AGENCE];
};

// -- PROTOTYPES --
// Construction des structures
void initialiseClient(int id, int compte, Client* cl);
void initialiseMaison(int id, int nbChambre, int prix, Maison* m);
void initialiseAgence(Agence* a);
// Affichage des structures
void affichageClient(Client cl);
void affichageMaison(Maison m);
// Achat d'une maison
void acheterMaison(Maison* m, Client* cl);
// Maisons non-vendus d'une agence
void maisonsNonVendus(Agence a);
// Ajout d'un client à une agence
void ajoutClient(Agence* a, Client* cl);
// Ajout d'une maison à une agence
void ajoutMaison(Agence* a, Maison* m);
// Client avec le plus de maison
int clientMaxMaisons(Agence a);

int main(void) {
  int clientMaxMaison;
  Client clients[20];
  Maison maisons[20];
  Agence agence;

  // Initialisation des clients et maisons
  initialiseClient(12, 300000, &clients[0]);
  initialiseClient(24, 2000000, &clients[1]);
  initialiseClient(33, 1000000, &clients[2]);
  initialiseMaison(11, 3, 250000, &maisons[0]);
  initialiseMaison(20, 5, 800000, &maisons[1]);
  initialiseMaison(345, 1, 600000, &maisons[2]);
  initialiseAgence(&agence);
  ajoutClient(&agence, &clients[0]);
  ajoutClient(&agence, &clients[1]);
  ajoutClient(&agence, &clients[2]);
  ajoutMaison(&agence, &maisons[0]);
  ajoutMaison(&agence, &maisons[1]);

  acheterMaison(&maisons[1], &clients[0]);
  acheterMaison(&maisons[1], &clients[2]);
  acheterMaison(&maisons[0], &clients[1]);
  acheterMaison(&maisons[2], &clients[1]);

  maisonsNonVendus(agence);

  clientMaxMaison = clientMaxMaisons(agence);
  printf("Le client avec le maximum de maison est le client %d\n", clientMaxMaison);

  return 0;
}

// -- IMPLEMENTATIONS --
// Construction des structures
void initialiseClient(int id, int compte, Client* cl) {
  cl->id = id;
  cl->compte = compte;
  cl->nbMaisons = 0;

  for(int i = 0; i <10; i++) {
    cl->maisons[i] = -1;
  }
}

void initialiseMaison(int id, int nbChambre, int prix, Maison* m) {
  m->id = id;
  m->nbChambre = nbChambre;
  m->prix = prix;
  m->vendue = false;
}

void initialiseAgence(Agence* a) {
  a->nbMaisons = 0;
  a->nbClients = 0;
}

// Affichage des structures
void affichageClient(Client cl) {
  printf("Client %d possède un compte de %d\n", cl.id, cl.compte);
}

void affichageMaison(Maison m) {
  if (m.nbChambre <= 1) {
    printf("Maison %d possède %d chambre et a un prix de %d\n", m.id, m.nbChambre, m.prix);
  } else {
    printf("Maison %d possède %d chambres et a un prix de %d\n", m.id, m.nbChambre, m.prix);
  }
}

void acheterMaison(Maison* m, Client* cl) {
  if (cl->nbMaisons < 10 && cl->compte >= m->prix) {
    m->vendue = true;
    cl->maisons[cl->nbMaisons] = m->id;
    cl->nbMaisons++;
    cl->compte = cl->compte - m->prix;
    printf("La maison %d a été vendue au client %d\n", m->id, cl->id);
  } else {
    printf("Le client %d n'a pas assez d'argent sur son compte\n", cl->id);
  }
}

// Maisons non-vendus d'une agence
void maisonsNonVendus(Agence a) {
  for (int i = 0; i < a.nbMaisons; i++) {
    if (!a.maisons[i]->vendue) {
      printf("La maison %d n'est pas vendue\n", a.maisons[i]->id);
    } else {
      printf("La maison %d est vendue\n", a.maisons[i]->id);
    }
  }
}

// Ajout d'un client à une agence
void ajoutClient(Agence* a, Client* cl) {
  if (a->nbClients < MAX_CLIENTS_AGENCE) {
    a->clients[a->nbClients] = cl;
    a->nbClients++;
  }
}

// Ajout d'une maison à une agence
void ajoutMaison(Agence* a, Maison* m) {
  if (a->nbMaisons < MAX_MAISONS_AGENCE) {
    a->maisons[a->nbMaisons] = m;
    a->nbMaisons++;
  }
}

// Client avec le maximum de maison
int clientMaxMaisons(Agence a) {
  int idClient = 0;

  for (int i = 1; i < a.nbClients; i++) {
    if(a.clients[i]->nbMaisons > a.clients[idClient]->nbMaisons) {
      idClient = i;
    }
  }

  return a.clients[idClient]->id;
}

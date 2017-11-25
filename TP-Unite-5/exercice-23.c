#include <stdio.h>

void occurencesLettres(char texte[]) {
  int position = 0;
  int occurences[26] = {0};

  do {
    // !! Possibilité de faire - 'a' et non pas - 97 !!
    if (texte[position] - 97 >= 0 && texte[position] - 97 < 26) {
      occurences[texte[position] - 97]++;
    }
  } while (texte[++position] != '\0');

  printf("Affichage du nombre d'occurences de chaque lettre du mot %s\n", texte);

  for (int i = 0; i < 26; i++) {
    printf("%c: %d ", i + 97, occurences[i]);
  }

  printf("\n");
}

int main(void) {
  occurencesLettres("bonjour");
  occurencesLettres("hello world!");
  occurencesLettres("test");

  return 0;
}

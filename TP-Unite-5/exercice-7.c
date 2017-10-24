#include <stdio.h>
#include <stdbool.h>

bool estUnPalindrome(char text[], int taille) {
  for(int i = 0; i < (taille / 2); i++) {
    if (text[i] != text[taille - 1 - i]) {
      return false;
    }
  }

  return true;
}

int main(void) {
  char tab1[] = {'s', 'u', 'g', 'u', 's'};
  char tab2[] = {'b', 'o', 'n', 'j', 'n', 'o', 'b'};

  if (estUnPalindrome(tab1, 5)) {
    printf("Le tableau 1 est un palindrome\n");
  }

  if (estUnPalindrome(tab2, 7)) {
    printf("Le tableau 2 est un palindrome\n");
  }
}

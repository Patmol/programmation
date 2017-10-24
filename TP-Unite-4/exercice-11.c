#include <stdio.h>
#include <stdbool.h>

#define MAX 70

bool multipleOuContientSept(int nombre) {
  if (nombre % 7 == 0 || nombre % 10 == 7 || nombre % 100 == 7) {
    return true;
  }

  return false;
}

int main(void) {
  for (int i = 1; i <= MAX; i++) {
    if(multipleOuContientSept(i)) {
      printf("bottle ");
    } else {
      printf("%d ", i);
    }
  }

  return 0;
}

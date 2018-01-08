#include <stdio.h>

void fct(int array[10]) {
    for (int i = 0 ; i < 10; i++) {
        printf("%d", array[i]);
    }
}

int main(void) {
    int array[5];

    for(int i = 0; i < 5; i++) {
        array[i] = i;
    }

/*
    for(int i = 0; i < 5; i++) {
        printf("%p\n", (array + i));
    }
    */

    fct(array);

    return 0;
}
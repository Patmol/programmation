#include <stdio.h>

int main(void) {
    int fahrenheit = 75;
    float celcius;

    while (fahrenheit < 100) {
        celcius = (5.0/9)*(fahrenheit - 32);
        printf("%i F° représente %.1f °C\n", fahrenheit, celcius);
        fahrenheit += 2;
    }

    return 0;
}

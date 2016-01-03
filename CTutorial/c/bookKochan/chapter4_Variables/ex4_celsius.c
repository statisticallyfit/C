#include <stdio.h>

float convertFromFahrenheitToCelsius(float fTemp) {
    return ((fTemp - 32)/1.8);
}

int main() {

    printf("Converting from Fahrenheit to Celsius\n");
    printf("Enter the temperature in degrees Fahrenheit: ");

    float fTemp;
    scanf("%f", &fTemp);

    printf("Celsius equivalent is: %f", convertFromFahrenheitToCelsius(fTemp));

    return 0;

}
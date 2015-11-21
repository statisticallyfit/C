#include <stdio.h>


int main() {

    float input = 0;
    float accumulator = 0;
    char operator = 'r'; //arbitrary

    printf("Begin calculations:\n");

    while (operator != 'E') {

        scanf("%f %c", &input, &operator);

        switch (operator){
            case 'S':
                accumulator = input;
                printf("= %f\n", accumulator);
                break;
            case '+':
                accumulator += input;
                printf("= %f\n", accumulator);
                break;
            case '-':
                accumulator -= input;
                printf("= %f\n", accumulator);
                break;
            case '*':
                accumulator *= input;
                printf("= %f\n", accumulator);
                break;
            case '/':
                if (input == 0) {
                    printf("Can't divide by zero!");
                } else {
                    accumulator = (accumulator / input);
                    printf("= %f\n", accumulator);
                }
                break;
            case 'E':
                printf("End of calculations.\n");
                break;
            default:
                printf("Unknown operator.");
                break;
        }
    }
}
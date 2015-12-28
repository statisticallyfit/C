#include <stdio.h>
//#include <c++/4.8/cmath>
#include <cmath>

double polynomial(double x) {
    return(std::pow(3*x, 3) - std::pow(5*x, 2) + 6);
}

int main() {
    double x;

    // use %ldf to represent a double! It is not %d as you might think...
    printf("Enter an x to plug into the polynomial: ");
    scanf("%lf", &x);

    printf("The answer is: %lf", polynomial(x));

    return 0;
}
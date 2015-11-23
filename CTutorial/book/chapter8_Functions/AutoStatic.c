#include <stdio.h>

void autoStatic() {

    int autoVar = 1;
    static int staticVar = 1;
    const int constVar = 1;

    printf("automatic = %i, static = %i, const = %i\n", autoVar, staticVar, constVar);

    autoVar++;
    staticVar++;
}


int main() {

    /**
     * Autovar is created and destroyed for each function execution
     * Static var remains
     */
    for (int i = 0; i < 5; i++){
        autoStatic();
    }
    return 0;
}
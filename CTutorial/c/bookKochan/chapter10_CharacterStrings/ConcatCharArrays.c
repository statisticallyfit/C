#include "../../../include/StringOp.h"


int main() {

    const char s1[5] = {'T', 'e', 's', 't', ' '};
    const char s2[6] = {'w', 'o', 'r', 'k', 's', '.'};
    char result[11];

    concat(result, s1, s2);

    for (int i = 0; i < 11; ++i){
        printf("%c", result[i]);
    }

    printf("\n");

    return 0;
}
#include <malloc.h>
#include <new>

class Box
{
public:
    double length;   // Length of a box
    double breadth;  // Breadth of a box
    double height;   // Height of a box
};


int main(int argc, char *argv[]) {

    void *memory = malloc(2 * sizeof(Box));

    new(memory) Box();
    //new(memory + sizeof(Box)) Box();

    return 0;
}

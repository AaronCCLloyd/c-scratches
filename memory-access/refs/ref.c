#include <stdio.h>

int main() {
    // Reference
    int x = 0;  // Declaring x
    int* y = &x; // Referencing x

    printf("Address of x = 0x%x\n", y);

    // Pointer
    int z = *y; // Declaring a pointer variable, dereferencing y
    printf("x = %d\n", z);

    return 0;
}
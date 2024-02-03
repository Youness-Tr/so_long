#include <stdio.h>

struct MyStruct {
    int x;
    float y;
    char z;
};

int main() {

    struct MyStruct stackStruct;
    static struct MyStruct staticStruct;
    //struct MyStruct* heapStruct = malloc(sizeof(struct MyStruct));
    stackStruct.x = 0, stackStruct.y = 0;

    printf("Stack struct: %d, %f, %c\n", stackStruct.x, stackStruct.y, stackStruct.z);
    printf("Static struct: %d, %f, %c\n", staticStruct.x, staticStruct.y, staticStruct.z);
   //printf("Heap struct: %d, %f, %c\n", heapStruct->x, heapStruct->y, heapStruct->z);

    //free(heapStruct);

    return 0;
}

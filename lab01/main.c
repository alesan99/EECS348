#include <stdio.h>
#include "isEven.h"
int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    isEven(num);
    return 0;
}

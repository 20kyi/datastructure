#include<stdio.h>
#include <stdlib.h>

#include "header/Calculator.h"

#define BUFFER_SIZE 10000

int main() {    
    char input[BUFFER_SIZE];
    scanf("%s", input);
    
    int result = Calculate(input);
    printf("result: %d\n", result);
    return 0;
}

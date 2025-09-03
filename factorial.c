#include <stdio.h>

int factorial(int n) {
    if (n < 0) return -1; // Error case
    
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    
    scanf("%d", &num);
    
    int result = factorial(num);
    
    if (result == -1) {
        printf("Error: Cannot calculate factorial of negative number\n");
    } else {
        printf("Factorial of %d is %d\n", num, result);
    }
    
    return 0;
}
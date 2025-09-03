#include <stdio.h>

int sumFibonacci(int n) {
    if (n <= 0) return 0;
    
    int a = 0, b = 1, sum = 0;
    
    while (a <= n) {
        sum += a;
        int next = a + b;
        a = b;
        b = next;
    }
    
    return sum;
}

int main() {
    int limit;
    
    scanf("%d", &limit);
    
    int result = sumFibonacci(limit);
    
    printf("Sum of Fibonacci sequence up to %d is %d\n", limit, result);
    
    return 0;
}
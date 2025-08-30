int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void fibonacciWithRecursion() {
    printf("\n=== FIBONACCI WITH RECURSION ===\n");
    int n;
    
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacciRecursive(i));
    }
    printf("\n");
}

long long factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

void factorialWithRecursion() {
    printf("\n=== FACTORIAL WITH RECURSION ===\n");
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return;
    }
    
    printf("Factorial of %d = %lld\n", n, factorialRecursive(n));
}

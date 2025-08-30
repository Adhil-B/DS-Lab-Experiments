#include <stdio.h>

int main() {
    int n, num;
    
    scanf("%d", &n);
    
    if (n <= 0) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            printf("%d is Even\n", num);
        } else {
            printf("%d is Odd\n", num);
        }
    }
    
    return 0;
}
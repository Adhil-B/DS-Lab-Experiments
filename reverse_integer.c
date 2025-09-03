#include <stdio.h>

int reverseInteger(int num) {
    int reversed = 0;
    
    while (num != 0) {
        int digit = num % 10;
        num = num / 10;
        
        // Check for overflow before it happens
        if (reversed > 214748364 || (reversed == 214748364 && digit > 7)) return 0; // Positive overflow
        if (reversed < -214748364 || (reversed == -214748364 && digit < -8)) return 0; // Negative overflow
        
        reversed = reversed * 10 + digit;
    }
    
    return reversed;
}

int main() {
    int num;
    
    scanf("%d", &num);
    
    int reversed = reverseInteger(num);
    
    printf("%d\n", reversed);
    
    return 0;
}
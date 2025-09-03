#include <stdio.h>
#include <string.h>

int isValidString(char str[]) {
    // Check if string is NULL or empty
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    // Simple validation - check if all characters are alphanumeric
    for (int i = 0; i < strlen(str); i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || 
              (str[i] >= 'A' && str[i] <= 'Z') || 
              (str[i] >= '0' && str[i] <= '9'))) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char str[100];
    
    scanf("%s", str);
    
    int isValid = isValidString(str);
    
    printf("%s\n", isValid ? "Valid string" : "Invalid string");
    
    return 0;
}
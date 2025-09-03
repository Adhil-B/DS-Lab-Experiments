#include <stdio.h>

int searchRegNo(int regNos[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (regNos[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int size;
    
    scanf("%d", &size);
    
    int regNos[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &regNos[i]);
    }
    
    int target;
    scanf("%d", &target);
    
    int position = searchRegNo(regNos, size, target);
    
    if (position != -1) {
        printf("Found at position %d\n", position);
    } else {
        printf("Not found\n");
    }
    
    return 0;
}
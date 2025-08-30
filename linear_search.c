#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, key, result;
    
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &key);
    
    result = linearSearch(arr, n, key);
    
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
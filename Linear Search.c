void linearSearch() {
    printf("\n=== LINEAR SEARCH ===\n");
    int arr[100], n, key, found = 0;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d\n", key, i);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Element %d not found in array\n", key);
    }
}

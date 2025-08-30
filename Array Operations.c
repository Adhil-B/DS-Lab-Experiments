void arrayOperations() {
    printf("\n=== ARRAY OPERATIONS ===\n");
    int arr[100], n, choice, pos, element;
    
    printf("Enter initial size of array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Display\n2. Insert\n3. Delete\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Array elements: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
                
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                
                if (pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for (int i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = element;
                    n++;
                    printf("Element inserted successfully!\n");
                }
                break;
                
            case 3:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                
                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Element deleted successfully!\n");
                }
                break;
                
            case 4:
                return;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}

struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

int getHeight(struct AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(struct AVLNode* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct AVLNode* createAVLNode(int data) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? 
                     getHeight(y->left) : getHeight(y->right));
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? 
                     getHeight(x->left) : getHeight(x->right));
    
    return x;
}

struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? 
                     getHeight(x->left) : getHeight(x->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? 
                     getHeight(y->left) : getHeight(y->right));
    
    return y;
}

struct AVLNode* insertAVL(struct AVLNode* node, int data) {
    if (node == NULL) return createAVLNode(data);
    
    if (data < node->data)
        node->left = insertAVL(node->left, data);
    else if (data > node->data)
        node->right = insertAVL(node->right, data);
    else
        return node;
    
    node->height = 1 + ((getHeight(node->left) > getHeight(node->right)) ? 
                        getHeight(node->left) : getHeight(node->right));
    
    int balance = getBalance(node);
    
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

struct AVLNode* minValueNode(struct AVLNode* node) {
    struct AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct AVLNode* deleteAVL(struct AVLNode* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteAVL(root->left, data);
    else if (data > root->data)
        root->right = deleteAVL(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct AVLNode* temp = root->left ? root->left : root->right;
            
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            
            free(temp);
        } else {
            struct AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteAVL(root->right, temp->data);
        }
    }
    
    if (root == NULL) return root;
    
    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? 
                        getHeight(root->left) : getHeight(root->right));
    
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

struct AVLNode* searchAVL(struct AVLNode* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    
    if (data < root->data)
        return searchAVL(root->left, data);
    
    return searchAVL(root->right, data);
}

void printInorderAVL(struct AVLNode* root) {
    if (root != NULL) {
        printInorderAVL(root->left);
        printf("%d ", root->data);
        printInorderAVL(root->right);
    }
}

void avlTreeOperations() {
    printf("\n=== AVL TREE OPERATIONS ===\n");
    struct AVLNode* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\nAVL Tree Menu:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertAVL(root, data);
                printf("Inserted %d into AVL tree\n", data);
                break;
                
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteAVL(root, data);
                printf("Deleted %d from AVL tree\n", data);
                break;
                
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchAVL(root, data) != NULL) {
                    printf("Element %d found in AVL tree\n", data);
                } else {
                    printf("Element %d not found in AVL tree\n", data);
                }
                break;
                
            case 4:
                printf("AVL Tree (Inorder): ");
                printInorderAVL(root);
                printf("\n");
                break;
                
            case 5:
                return;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}

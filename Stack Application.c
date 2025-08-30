int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix() {
    printf("\n=== INFIX TO POSTFIX CONVERSION ===\n");
    char infix[100], postfix[100], stack[100];
    int top = -1, j = 0;
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // Remove '('
        } else if (isOperator(infix[i])) {
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }
    
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

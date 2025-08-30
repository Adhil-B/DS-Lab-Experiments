#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

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

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];
        
        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(current);
        } else if (current == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else if (isOperator(current)) {
            while (!isEmpty() && precedence(peek()) >= precedence(current) && peek() != '(') {
                postfix[j++] = pop();
            }
            push(current);
        }
    }
    
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("%s\n", postfix);
    
    return 0;
}
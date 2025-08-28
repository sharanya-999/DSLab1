
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop function
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

// Peek function
char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}

// Function to define operator precedence
int precedence(char op) {
    switch (op) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char symbol;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        // Operand? Directly add to postfix
        if (isalnum(symbol)) {
            postfix[k++] = symbol;
        }
        // Left parenthesis? Push to stack
        else if (symbol == '(') {
            push(symbol);
        }
        // Right parenthesis? Pop until '('
        else if (symbol == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
        // Operator
        else if (isOperator(symbol)) {
            while (top != -1 && precedence(peek()) >= precedence(symbol)) {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


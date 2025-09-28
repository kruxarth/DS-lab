#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <stdlib.h>  // for atoi()

#define MAX 100

// Stack implementation
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            // Convert char digit to int and push
            push(ch - '0');
        }
        else {
            // Operator: pop two operands
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default: printf("Invalid operator: %c\n", ch);
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}

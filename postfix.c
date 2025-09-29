#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h>  

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int val1 = pop(); 
            int val2 = pop(); 

            switch (ch) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
                default: printf("Invalid operator: %c\n", ch); exit(1);
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

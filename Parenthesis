#include <stdio.h>
#include <string.h>

#define MAX 100 

int pValidation(char str[]) {
    char stack[MAX];
    int top = -1; 

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

     
        if (ch == '(' || ch == '[' || ch == '{') {
            if (top == MAX - 1) {
                printf("Error: Stack overflow!\n");
                return 0;
            }
            stack[++top] = ch;
        }

        else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1)
                return 0;

            char topChar = stack[top--]; 

            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{')) {
                return 0; 
            }
        }
    }

    return (top == -1);
}

int main() {
    char expr[200];

    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = 0;

    if (pValidation(expr))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are NOT balanced.\n");

    return 0;
}

 #include <stdio.h>
#include <string.h>

int pValidation(char str[]) {
    int i, top = -1;
    char s[20];

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s[++top] = str[i];
        }
        else if (str[i] == ')') {
            if (top == -1 || s[top] != '(')
                return 0;
            top--;
        }
        else if (str[i] == ']') {
            if (top == -1 || s[top] != '[')
                return 0;
            top--;
        }
        else if (str[i] == '}') {
            if (top == -1 || s[top] != '{')
                return 0;
            top--;
        }
    }

    return (top == -1);
}

int main() {
    char expr[100];

    printf("Enter expression: ");
    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = 0;

    if (pValidation(expr))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are NOT balanced.\n");

    return 0;
}



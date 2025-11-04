#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int top=-1;
double s[20];
double compute(char symbol, double op1, double op2){
    switch(symbol){
        case '+': return op1+op2;
        break;
        case '-': return op1-op2;
        break;
        case '*': return op1*op2;
        break;
        case '/': return op1/op2;
        break;
        case '^': return pow(op1,op2);
        break;
    }
}
void main(){
    double res, op1, op2;
    int i;
    char postfix[20], symbol;
    printf("Enter a postfix expression:\n");
    scanf("%s",postfix);

    for(i=0;i<strlen(postfix);i++){
        symbol = postfix[i];
        if(isdigit(symbol)){
            s[++top] = symbol - '0';
        }
        else{
            op2 = s[top--];
            op1 = s[top--];
            res = compute(symbol, op1 , op2);
            s[++top] = res;
        }
    }
    res = s[top--];
    printf("\n Result: %f",res);
}

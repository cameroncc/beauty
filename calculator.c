#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int a, b, ans;
    char input[100];
    int j = 0;
fillInput:
    if(j < 100) {
        input[j] = '\0';
        ++j;
        goto fillInput;
    }
    j = 0;
    char op[100];
fillOp:
    if(j < 100) {
        op[j] = '\0';
        ++j;
        goto fillOp;
    }
    char opChar;
    void* opGoto;

chooseOp:
    printf("Do you want to add, subtract, multiply, or divide? ");
    fgets(op, 100, stdin);
    if(op[10] != '\0') {
        goto invalidOp;
    }

    int i = 0;
    char c;
opLength:
    if((c = op[i]) != '\0') {
        if(c != '\n') {
            c = op[++i];
        } else {
            op[i] = '\0';
            goto validateOp;
        after:
            printf("%d %c %d = %d\n", a, opChar, b, ans);
            return 0;
        }
        goto opLength;
    }

sub:
    ans = a - b;
    goto after;

validateOp:
    if(strcmp(op, "add") == 0) {
        opChar = '+';
        opGoto = &&add;
    } else if(strcmp(op, "subtract") == 0) {
        opChar = '-';
        opGoto = &&sub;
    } else if(strcmp(op, "multiply") == 0) {
        opChar = '*';
        opGoto = &&mult;
    } else if(strcmp(op, "divide") == 0) {
        opChar = '/';
        opGoto = &&div;
    } else {
    invalidOp:
        printf("Invalid operation \"%s\", try again.\n\n", op);
        goto chooseOp;
    div:
        ans = a / b;
        goto after;
    }
    goto getNums;

add:
    ans = a + b;
    goto after;

getNums:
    printf("Enter the first number to %s: ", op);
    a = atoi(fgets(input, 100, stdin));
    printf("Enter the second number to %s: ", op);
    b = atoi(fgets(input, 100, stdin));
    printf("\n");
    goto *opGoto;
    
mult:
    ans = a * b;
    goto after;
}
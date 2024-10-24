#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <cstring.h>

char stack[100];
int top = -1;

int prec(char c) {
    switch (c) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
        default:
            return -1;
    }
}

char reverse(char str[]) {
    int s = strlen(str);

    for (int i = 0; i < s / 2; i++) {
        char temp = str[i];
        str[i] = str[s - i - 1];
        str[s - i - 1] = temp;
    }

    return str;
}

char infixTopostfix(char infix[]) {
    static char postfix[100];
    int len = strlen(infix);
    int i, j = 0;

    for (i = 0; i < len; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top == -1) {
                return '!';
            } else {
                top--;
            }
        } else if (infix[i] == '(') {
            stack[++top] = '(';
        } else {
            while (top != -1 && prec(infix[i]) <= prec(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    return postfix;
}

char infixToPrefix(char infix[]) {
    static char postfix[100];
    int len = strlen(infix);
    int i, j = 0;

    reverse(infix);

    for (i = 0; i < len; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = ')';
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top == -1) {
                return '!';
            } else {
                top--;
            }
        } else {
            while (top != -1 && prec(infix[i]) <= prec(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    reverse(postfix);

    return postfix;
}

void main() {
    clrscr();

    char infix[100];

    cout << "Enter an infix expression: ";
    cin >> infix;

    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << infixTopostfix(infix) << endl;
    cout << "Prefix expression: " << infixToPrefix(infix) << endl;

    getch();
}
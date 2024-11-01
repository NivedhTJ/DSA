#include <stdio.h>
#define size 20

int stack[size];
int top = 0;

// Check precedence of operator
int prece(char oper) {
	switch (oper) {
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 4;
	case '^':
		return 5;
	default:
		return 0;
	}
}

// Check if stack is full
int isfull() {
	return top >= size;
}

// Check if stack is empty
int isempty() {
	return top == 0;
}

// Push item to stack
void push(int item) {
	if (isfull())
		printf("Stack is full\n");
	else {
		stack[top] = item;
		top++;
	}
}

// Pop item from stack and return the item
int pop() {
	if (isempty()) {
		printf("Stack is empty\n");
		return -1;
	} else {
		top--;
		return stack[top];
	}
}

// Return item at the top
int peek() {
	if (isempty()) {
		printf("Stack is empty\n");
		return -1;
	} else
		return stack[top - 1];
}

int main() {
	char infix[20];
	char postfix[20];
	int i, j, c;

	printf("Enter the infix expression: ");
	scanf("%s", infix);

	for (i = 0, j = 0; infix[i] != '\0'; i++) {
		char token = infix[i];

		switch (token) {
		case '(':
			push(token);
			break;

		case ')':
			while ((c = pop()) != '(')
				postfix[j++] = c;
			break;
			
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			while (!isempty() && (prece(peek()) >= prece(token)))
				postfix[j++] = pop();
			push(token);
			break;

		default:
			postfix[j++] = token;
		}
	}

	while (!isempty()) {
		postfix[j++] = pop();
	}

	postfix[j] = '\0';

	// Print the final postfix expression
	printf("Postfix = %s\n", postfix);

	return 0;
}

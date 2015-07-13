// scanner.h
// 栈的案例：就近匹配

#include "stdio.h"
#include "stdlib.h"
#include "linkstack.h"

int isLeft(char c)
{
	int ret = 0;

	switch (c) {
	case '<':
	case '(':
	case '[':
	case '{':
		ret = 1;
		break;
	default:
		break;
	}

	return ret;
}

int isRight(char c)
{

	int ret = 0;

	switch (c) {
	case '>':
	case ')':
	case ']':
	case '}':
		ret = 1;
		break;
	default:
		break;
	}

	return ret;
}

int match(char left, char right)
{
	int ret = 0;

	switch (left) {
	case '<':
		ret = (right == '>');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '\'':
		ret = (right == '\'');
		break;
	case '\"':
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

void scanner(const char* code)
{
	LinkStack *stack = LinkStack_Create();
	int i = 0;

	while (code[i] != '\0') {
		if (isLeft(code[i])) {
			LinkStack_Push(stack, (void *)&code[i]);
		}

		if (isRight(code[i])) {
			char *c = (char *)LinkStack_Pop(stack);

			if (c == NULL || !match(*c, code[i])) {
				printf("%c does not match!\n", code[i]);
				break;
			}
		}

		++i;
	}

	if (LinkStack_Size(stack) == 0 && code[i] == '\0') {
		printf("Success!\n");
	}
	else {
		printf("Fail!\n");
	}

	LinkStack_Destroy(stack);
}

void playScanner()
{
	const char* code = "#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0; ";

	scanner(code);

	return;
}
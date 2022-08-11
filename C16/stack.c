
#include <stdlib.h>
#include "stack.h"

struct stack_element
{
	int element;
	struct stack_element* prev;
};
typedef struct stack_element* stack;

int push(stack* _stack, int _element)
{
	stack newStack;
	if (*_stack == NULL)
	{
		if ((*_stack = (stack)malloc(sizeof(stack))) == NULL)
		{
			return -1;
		}

		(*_stack)->element = _element;
		(*_stack)->prev = NULL;
		return 0;
	}

	if ((newStack = (stack)calloc(1, sizeof(stack))) == NULL)
	{
		return -1;
	}

	newStack->element = _element;
	newStack->prev = *_stack;
	*_stack = newStack;
	return 0;
}

int pop(stack* _stack)
{
	stack ejectedStruct = *_stack;
	stack prevStruct = *_stack;
	int ejectedElement;
	int i = 0;

	if (*_stack == NULL)
	{
		return 0;
	}
	if (ejectedStruct->prev == NULL)
	{
		ejectedElement = ejectedStruct->element;
		free(*_stack);
		*_stack = NULL;
	}
	else
	{
		while (ejectedStruct->prev != NULL)
		{
			prevStruct = ejectedStruct;
			ejectedStruct = ejectedStruct->prev;
		}
		ejectedElement = ejectedStruct->element;
		free(ejectedStruct);
		prevStruct->prev = NULL;
		*_stack = prevStruct;
	}
	return ejectedElement;
}

void delete_stack(stack* _stack)
{
	while (pop(_stack)) {}
	return;
}
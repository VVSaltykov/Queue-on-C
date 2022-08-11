#include <stdio.h>
#include "stack.h"

struct stack_element
	{
		int element;
		struct stack_element* prev;
	};
	typedef struct stack_element* stack;

	void main()
{
		stack newStack = NULL;

		for (;;)
		{
			int choice;

			printf("CHOOSE AN ACTION:\n");
			printf("1 - Push an item onto the stack\n");
			printf("2 - Pop an item from the stack\n");
			printf("3 - Delete stack\n");
			printf("Another number - End program\n");
			printf("\nYour choice - ");
			scanf("%d", &choice);
			if ((choice != 1) && (choice != 2) && (choice != 3))
			{
				break;
			}
			if (choice == 1)
			{
				int stackElement;

				printf("Introduce the item to add to the stack\n");
				scanf("%d", &stackElement);

				if (push(&newStack, stackElement) == -1)
				{
					printf("ERROR\n\n");
				}
				else
				{
					printf("Success\n\n");
				}
			}
			if (choice == 2)
			{
				if (pop(&newStack) == 0)
				{
					printf("The stack is empty\n\n");
				}
				else
				{
					printf("Success\n\n");
				}
			}
			if (choice == 3)
			{
				delete_stack(&newStack);
				printf("Stack removed\n\n");
			}
		}
		printf("The program is over");
}
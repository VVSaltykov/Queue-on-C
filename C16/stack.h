typedef struct stack_element* stack;
int push(stack* _stack, int _element);
int pop(stack* _stack);
void delete_stack(stack* _stack);
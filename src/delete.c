#include "../push_swap.h"

void printlst(t_stack *stack)
{

	while (stack != NULL)
	{
		printf("[%d]---", stack->data);
		stack = stack->next;
	}
	printf("[END]\n\n");
}

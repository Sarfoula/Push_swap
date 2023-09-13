#include "../push_swap.h"

void printlst(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		printf("[%d]---", tmp->data);
		tmp = tmp->next;
	}
	printf("[END]\n");
}

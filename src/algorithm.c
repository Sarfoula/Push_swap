/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:56:24 by yallo             #+#    #+#             */
/*   Updated: 2023/09/28 15:34:11 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->data;
	b = get_data(stack, 2)->data;
	c = get_data(stack, 3)->data;
	if ((a >= b && a <= c) || (a <= b && a >= c))
		return a;
	if ((b <= a && b >= c) || (b >= a && b <= c))
		return b;
	return c;
}

void quicksort(t_stack **stack)
{
	int pivot;
	t_stack *petit = NULL;
	t_stack *grand = NULL;

	if ((*stack)->next == NULL || *stack == NULL)
		return ;
	pivot = find(*stack);
	while (*stack != NULL)
	{
		if ((*stack)->data > pivot)
			add_stack(&grand, (*stack)->data);
		else
			add_stack(&petit, (*stack)->data);
	*stack = (*stack)->next;
	}
	if (size_stack(petit) > 2)
		quicksort(&petit);
	if (size_stack(grand) > 2)
		quicksort(&grand);
	last_node(petit)->next = grand;
	*stack = petit;
}

void	transform(t_stack **stack)
{
	size_t	i;
	size_t	j;
	t_stack *sorted;

	sorted = *stack;
	quicksort(&sorted);
	printlst(sorted);
	i = 0;
	while (i < size_stack(*stack))
	{
		j = 0;
		while (j < size_stack(sorted))
		{
			if (get_data(*stack, i)->data == get_data(sorted, j)->data)
				get_data(*stack, i)->data = j;
			j++;
		}
		i++;
	}
}

void algorithm(t_stack **stack_a, t_stack **stack_b)
{
	printlst(*stack_a);
	transform(stack_a);
	(void)stack_b;
}

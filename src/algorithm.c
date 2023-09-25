/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:56:24 by yallo             #+#    #+#             */
/*   Updated: 2023/09/25 17:18:58 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->data;
	b = get_data(stack, 2);
	c = get_data(stack, 3);
	if ((a >= b && a <= c) || (a <= b && a >= c))
		return a;
	if ((b <= a && b >= c) || (b >= a && b <= c))
		return b;
	return c;
}

void quicksort(t_stack **test)
{
	int pivot;
	t_stack *petit = NULL;
	t_stack *grand = NULL;
	t_stack *stack = *test;

	if (stack->next == NULL ||stack == NULL)
		return ;
	pivot = find(stack);
	while (stack != NULL)
	{
		if (stack->data > pivot)
			add_stack(&grand, stack->data);
		else
			add_stack(&petit, stack->data);
	stack = stack->next;
	}
	if (size_stack(petit) > 2)
		quicksort(&petit);
	if (size_stack(grand) > 2)
		quicksort(&grand);
	last_node(petit)->next = grand;
	*test = petit;
}

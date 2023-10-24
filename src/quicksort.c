/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 01:27:40 by yallo             #+#    #+#             */
/*   Updated: 2023/10/24 16:08:44 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_median(t_stack *stack, int size)
{
	int	a;
	int	b;
	int	c;

	a = stack->data;
	b = get_data(stack, 1)->data;
	if (size > 2)
	{
		c = get_data(stack, 2)->data;
		if ((a >= b && a <= c) || (a <= b && a >= c))
			return (a);
		if ((b <= a && b >= c) || (b >= a && b <= c))
			return (b);
		return (c);
	}
	else
		if (a > b)
			return (b);
	return (a);
}

void	tri(t_stack **stack, t_stack **petit, t_stack **grand, int pivot)
{
	t_stack	*tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		if (tmp->data > pivot)
		{
			if (*grand == NULL)
				*grand = tmp;
			else
				last_node(*grand)->next = tmp;
		}
		else
		{
			if (*petit == NULL)
				*petit = tmp;
			else
				last_node(*petit)->next = tmp;
		}
	}
}

void	quicksort(t_stack **stack)
{
	int		pivot;
	int		size;
	t_stack	*petit;
	t_stack	*grand;

	grand = NULL;
	petit = NULL;
	size = (int)size_stack(*stack);
	if (size < 2)
		return ;
	pivot = find_median(*stack, size);
	tri(stack, &petit, &grand, pivot);
	quicksort(&petit);
	quicksort(&grand);
	last_node(petit)->next = grand;
	*stack = petit;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:56:24 by yallo             #+#    #+#             */
/*   Updated: 2023/10/19 02:38:42 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find(t_stack *stack, int size)
{
	int	a;
	int b;
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

void tri(t_stack **stack, t_stack **petit, t_stack **grand, int pivot)
{
	t_stack *tmp;

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

void quicksort(t_stack **stack)
{
	int pivot;
	int size;
	t_stack *petit = NULL;
	t_stack *grand = NULL;

	size = (int)size_stack(*stack);
	if (size < 2)
		return ;
	pivot = find(*stack, size);
	tri(stack, &petit, &grand, pivot);
	quicksort(&petit);
	quicksort(&grand);
	last_node(petit)->next = grand;
	*stack = petit;
}

void	transform(t_stack **stack, t_stack *sorted)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size_stack(*stack))
	{
		j = 0;
		while (j < size_stack(sorted))
		{
			if (get_data(*stack, i)->data == get_data(sorted, j)->data)
			{
				get_data(*stack, i)->data = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void radixsort(t_stack **stack_a, t_stack **stack_b)
{
	int		num;
	size_t	size = size_stack(*stack_a);
	size_t	max_bits = 0;
	size_t	i;
	size_t j = 0;

	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (j < max_bits)
	{
		i = 0;
		while (i < size)
		{
			num = (*stack_a)->data;
			if ((num >> j) & 1)
				rotate(stack_a, "ra");
			else
				push(stack_b, stack_a, "pb");
			i++;
		}
		while (size_stack(*stack_b) > 0)
			push(stack_a, stack_b, "pa");
		j++;;
	}
}

void	copy(t_stack *stack, t_stack **sorted)
{
	while (stack != NULL)
	{
		add_stack(sorted, stack->data);
		stack = stack->next;
	}
}

void algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *sorted;

	sorted = NULL;
	copy(*stack_a, &sorted);
	quicksort(&sorted);
	transform(stack_a, sorted);
	free_all(sorted, NULL, NULL);
	radixsort(stack_a, stack_b);
}

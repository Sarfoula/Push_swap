/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:38:20 by yallo             #+#    #+#             */
/*   Updated: 2023/10/24 13:59:18 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *stack)
{
	size_t	i;
	int		min;

	i = size_stack(stack) - 1;
	min = 0;
	while (i > 0)
	{
		if (get_data(stack, min)->data > get_data(stack, i)->data || i == 0)
			min = i;
		i--;
	}
	return (min);
}

void	three(t_stack **stack)
{
	if ((*stack)->data > get_data(*stack, 1)->data)
		swap(stack, "sa\n");
	if (get_data(*stack, 1)->data > get_data(*stack, 2)->data)
		reverse_rotate(stack, "rra\n");
	if ((*stack)->data > get_data(*stack, 1)->data)
		swap(stack, "sa\n");
}

void	five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	min;

	i = 0;
	while (i < 2)
	{
		min = find_min(*stack_a);
		while (min > 0)
		{
			rotate(stack_a, "ra\n");
			min--;
		}
		push(stack_b, stack_a, "pb\n");
		i++;
	}
	three(stack_a);
	push(stack_a, stack_b, "pa\n");
	push(stack_a, stack_b, "pa\n");
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*sorted;

	tmp = *stack_a;
	sorted = NULL;
	while (tmp != NULL)
	{
		add_stack(&sorted, tmp->data);
		tmp = tmp->next;
	}
	quicksort(&sorted, 1);
	translate(stack_a, sorted);
	radixsort(stack_a, stack_b);
	free_all(sorted, NULL, NULL);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = size_stack(*stack_a);
	if (size == 3)
		three(stack_a);
	else if (size == 5)
		five(stack_a, stack_b);
	else
		algorithm(stack_a, stack_b);
}

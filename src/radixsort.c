/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 01:28:54 by yallo             #+#    #+#             */
/*   Updated: 2023/10/20 01:32:28 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	translate(t_stack **stack, t_stack *sorted)
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

void radixsort(t_stack **stack_a, t_stack **stack_b, t_stack *sorted)
{
	int		num;
	size_t	size = size_stack(*stack_a);
	size_t	max_bits = 0;
	size_t	i;
	size_t j = 0;

	translate(stack_a, sorted);
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

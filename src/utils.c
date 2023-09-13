/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:08:32 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 20:08:32 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void free_stack(t_stack *stack)
{
	t_stack *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

t_stack *last_node(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	add_stack(t_stack **stack, int data)
{
	t_stack *new_node;
	t_stack *last;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (1);
	new_node->next = NULL;
	new_node->data = data;
	if (*stack == NULL)
	{
		*stack = new_node;
		return (0);
	}
	last = last_node(*stack);
	last->next = new_node;
	return (0);
}

size_t size_stack(t_stack *stack)
{
	size_t	count;

	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
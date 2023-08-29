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


void free_stack(list *stack)
{
	list *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

list *last_node(list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	add_stack(list **stack, int data)
{
	list *new_node;
	list *last;

	new_node = malloc(sizeof(list));
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

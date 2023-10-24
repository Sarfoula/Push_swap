/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:55:34 by yallo             #+#    #+#             */
/*   Updated: 2023/10/24 13:56:38 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack, char *str)
{
	t_stack	*temp;

	if (size_stack(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (str != NULL)
		write(1, str, ft_strlen(str));
}

void	push(t_stack **to, t_stack **from, char *str)
{
	t_stack	*temp;

	if (size_stack(*from) < 1)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	if (size_stack(*from) == 0)
		*from = NULL;
	if (str != NULL)
		write(1, str, ft_strlen(str));
}

void	rotate(t_stack **stack, char *str)
{
	t_stack	*last;
	t_stack	*temp;

	if (size_stack(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last = last_node(*stack);
	last->next = temp;
	if (str != NULL)
		write(1, str, ft_strlen(str));
}

void	reverse_rotate(t_stack **stack, char *str)
{
	t_stack	*temp;
	t_stack	*last;

	if (size_stack(*stack) < 2)
		return ;
	temp = *stack;
	while ((temp->next)->next != NULL)
		temp = temp->next;
	last = last_node(*stack);
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
	if (str != NULL)
		write(1, str, ft_strlen(str));
}

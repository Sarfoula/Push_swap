/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:28:03 by yallo             #+#    #+#             */
/*   Updated: 2023/10/20 01:39:54 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_str(char **split)
{
	int i;
	int j;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j])
		{
			if (((split[i][j] < 48 || split[i][j] > 57) && split[i][j] != '-' && split[i][j] != '+') || j > 11)
				return (1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

int check_digit(t_stack *stack)
{
	t_stack *temp;

	if (size_stack(stack) < 2)
		return (1);
	while (stack->next != NULL)
	{
		temp = stack->next;
		while (temp != NULL)
		{
			if (stack->data == temp->data)
				return (1);
			temp = temp->next;	
		}
		stack = stack->next;
	}
	return (0);
}

int parse(char *str, t_stack **stack)
{
	int i;
	long data;
	char **split;

	i = 0;
	split = ft_split(str, ' ');
	if (check_str(split) == 1)
		return (free_all(NULL, split, "Error\nArgument not a list of integers\n"), 1);
	while (split[i] != NULL)
	{
		data = ft_atoi(split[i]);
		if (data > 2147483647 || data < -2147483648)
			return (free_all(*stack, split, "Error\nIntegers has limits\n"), 1);
		if (add_stack(stack, data) == 1)
			return (free_all(*stack, split, "Malloc failed"), 1);
		i++;
	}
	if (check_digit(*stack) == 1)
		return (free_all(*stack, split, "Error\nThere is a duplicate !!!\n"), 1);
	free_all(NULL, split, NULL);
	return (0);
}

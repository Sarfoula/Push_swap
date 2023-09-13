/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:28:03 by yallo             #+#    #+#             */
/*   Updated: 2023/08/30 16:28:03 by yallo            ###   ########.fr       */
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
			if ((split[i][j] < 48 || split[i][j] > 57) && split[i][j] != '-' && split[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_double(t_stack *stack)
{
	t_stack *temp;

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
	char **split;

	i = 0;
	split = ft_split(str, ' ');
	if (check_str(split) == 1)
		return (ft_printf(""), 1);
	while (split[i] != NULL)
	{
		add_stack(stack, ft_atoi(split[i]));
		free(split[i]);
		i++;
	}
	free(split);
	if (check_double(*stack) == 1)
		return (ft_printf("There is a duplicate !!!"), 1);
	return (0);
}

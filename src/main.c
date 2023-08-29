/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 00:21:23 by yallo             #+#    #+#             */
/*   Updated: 2023/08/28 00:21:23 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void printlst(list *stack)
{
	list *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		ft_printf("[%d]---", tmp->data);
		tmp = tmp->next;
	}
}

int main(int argc, char **argv)
{
	list *stack;

	stack = NULL;
	if ((argc > 2) | (argc == 1))
		return (ft_printf("Wrong numbers of argument:\n./push_swap \"NUMBERS\""), 0);
	int i = 0;
	while (i < 3)
	{
		i++;
		add_stack(&stack, i*10);
	}
	printlst(stack);
	free_stack(stack);
	(void)argv;
	return (0);
}

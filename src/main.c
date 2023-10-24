/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 00:21:23 by yallo             #+#    #+#             */
/*   Updated: 2023/10/24 16:01:33 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > (stack->next)->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if ((argc > 2) | (argc == 1))
		return (write(2, \
			"Wrong numbers of argument:\n./push_swap \"NUMBERS\"\n", 50), 0);
	if (parse(argv[1], &stack_a) == 1)
		return (0);
	if (is_sorted(stack_a) == 1)
		return (free_all(stack_a, NULL, "The list is already sorted\n"), 0);
	sort(&stack_a, &stack_b);
	free_all(stack_a, NULL, NULL);
	return (0);
}

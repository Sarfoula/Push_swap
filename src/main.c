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

int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack	*stack_b = NULL;

	if ((argc > 2) | (argc == 1))
		return (ft_printf("Wrong numbers of argument:\n./push_swap \"NUMBERS\""), 0);
	if (parse(argv[1], &stack_a) == 1)
		return (0);
	add_stack(&stack_b, 10);
	add_stack(&stack_b, 20);
	push(&stack_a, &stack_b);
	printlst(stack_a);
	free_stack(stack_a);
	return (0);
}

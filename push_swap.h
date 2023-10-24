/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:44:24 by yallo             #+#    #+#             */
/*   Updated: 2023/10/24 16:09:01 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

//Utils
void	free_all(t_stack *stack, char **str, char *display);
t_stack	*last_node(t_stack *stack);
int		add_stack(t_stack **stack, int data);
size_t	size_stack(t_stack *stack);
t_stack	*get_data(t_stack *stack, size_t index);

//Parse
int		check_str(char **split);
int		check_digit(t_stack *stack);
int		parse(char *str, t_stack **stack);

//Swap 1 & 2
void	swap(t_stack **stack, char *str);
void	push(t_stack **to, t_stack **from, char *str);
void	rotate(t_stack **stack, char *str);
void	reverse_rotate(t_stack **stack, char *str);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//Radixsort
void	translate(t_stack **stack, t_stack *sorted);
void	radixsort(t_stack **stack_a, t_stack **stack_b);

//Quicksort
int		find_median(t_stack *stack, int size);
void	tri(t_stack **stack, t_stack **petit, t_stack **grand, int pivot);
void	quicksort(t_stack **stack);

//Sort
int		find_min(t_stack *stack);
void	three(t_stack **stack);
void	five(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	algorithm(t_stack **stack_a, t_stack **stack_b);

#endif
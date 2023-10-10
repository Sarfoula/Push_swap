/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:56:24 by yallo             #+#    #+#             */
/*   Updated: 2023/10/10 19:29:14 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack* partition(t_stack* head, t_stack* end, t_stack** newHead, t_stack** newEnd) {
    t_stack* pivot = end;
    t_stack* prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (*newHead == NULL)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            t_stack* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;
    return pivot;
}

t_stack* quickSortRec(t_stack* head, t_stack* end) {
    if (!head || head == end)
        return head;

    t_stack* newHead = NULL, *newEnd = NULL;
    t_stack* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        t_stack* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRec(newHead, tmp);
        tmp = last_node(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRec(pivot->next, newEnd);
    return newHead;
}

void simple(t_stack *stack)
{
	t_stack	*head;
	int		temp;

	head = stack;
	while (is_sorted(stack) == 0)
	{
		if (stack->data > (stack->next)->data)
		{
			temp = stack->data;
			stack->data = (stack->next)->data;
			(stack->next)->data = temp;
			stack = head;
		}
		else
			stack = stack->next;
	}
}

void	transform(t_stack **stack, t_stack *sorted)
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
				//ft_printf("%d == %d\n", get_data(*stack, i)->data, j);
				get_data(*stack, i)->data = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void radixsort(t_stack **stack_a, t_stack **stack_b)
{
	int		num;
	size_t	size = size_stack(*stack_a);
	size_t	max_bits = 0;
	size_t	i;
	size_t j = 0;

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

void	copy(t_stack *stack, t_stack **sorted)
{
	while (stack != NULL)
	{
		add_stack(sorted, stack->data);
		stack = stack->next;
	}
}

void algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *sorted;

	sorted = NULL;
	copy(*stack_a, &sorted);
	quickSortRec(sorted, last_node(sorted));
	transform(stack_a, sorted);
	radixsort(stack_a, stack_b);
	free_all(sorted, NULL, NULL);
}

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
typedef struct	s_stack
{
	int 			data;
	struct s_stack	*next;
}				t_stack;

//Delete
void printlst(t_stack *stack);

//Utils
int	add_stack(t_stack **stack, int data);
t_stack *last_node(t_stack *stack);
void free_stack(t_stack *stack);
size_t size_stack(t_stack *stack);

//Parse
int parse(char *str, t_stack **stack);

//Swap
void swap(t_stack **stack, char *str);
void push(t_stack **to, t_stack **from, char *str);
void rotate(t_stack **stack, char *str);
void reverse_rotate(t_stack **stack, char *str);
void ss(t_stack **stack_a, t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);

#endif
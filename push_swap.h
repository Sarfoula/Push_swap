#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
typedef struct	s_stack
{
	int 			data;
	int				size;
	struct s_stack	*next;
}				t_stack;

//Delete
void printlst(t_stack *stack);

//Utils
int	add_stack(t_stack **stack, int data);
t_stack *last_node(t_stack *stack);
void free_all(t_stack *stack, char **str, char *display);
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

//Algorithm
int get_data(t_stack *stack, size_t index);
void sort(t_stack **stack_a, t_stack **stack_b);
void algorithm(t_stack **stack_a, t_stack **stack_b);
void quicksort(t_stack **stack);
int is_sorted(t_stack *stack);

#endif
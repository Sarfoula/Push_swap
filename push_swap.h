#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

//Utils
typedef struct	s_stack
{
	int 			data;
	struct s_stack	*next;
}				list;
int	add_stack(list **stack, int data);
list *last_node(list *stack);
void free_stack(list *stack);

#endif
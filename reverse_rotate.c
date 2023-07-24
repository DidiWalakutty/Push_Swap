/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 17:08:18 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/24 12:48:19 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse Rotate:
//	rra - reverse rotate a -		Shift down all elements of stack a by 1.
//	rrb - reverse rotate b -		Shift down all elements of stack b by 1.
//	rrr - reverse rotate both -		Shift down both at once.
//									Last element becomes the first.

// Ultimate_last finds the second to last position, so it can set it to NULL in rev_rotate.
static t_stack	*ultimate_last(t_stack *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

// To avoid an infinite loop, add_front is done *after* finding the ultimate_last, so 
// we can set the ultimate 'last' in stack to NULL, after putting 'top' at first position in stack.
static void	rev_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	if (count_stacks(*stack) <= 1)
		return ;
	top = last_stack(*stack);
	last = ultimate_last(*stack);
	add_front(stack, top);
	last->next = NULL;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}

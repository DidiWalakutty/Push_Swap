/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 13:34:05 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/26 20:04:45 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate:
//	ra - rotate a -		Shift up all elements of stack a by 1.
//	rb - rotate b -		Shift up all elements of stack b by 1.
//	rr - rotate both -	Shift up both at once.
//						First element becomes the last.

// Second_to_last points to the last node, which will become 2nd_to_last node.
// Last points to the first node, which will become the last node.
// Stack updates to 2nd node in stack, making it the new head.
// Break the link from last, so it becomes the last node.
// 2nd_to_last now points to last, effectively shifting to become 2nd_to_last.
static void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_to_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_to_last = last_stack(*stack);
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	second_to_last->next = last;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}

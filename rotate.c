/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 13:34:05 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/16 18:18:42 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate:
//	ra - rotate a -		Shift up all elements of stack a by 1.
//	rb - rotate b -		Shift up all elements of stack b by 1.
//	rr - rotate both -	Shift up both at once.
//						First element becomes the last.

// Last is set to the current first node, which will become the last node.
// Second_to_last is set to the current last node, which will become the second to last node.
// Stack is set to the second node, now the head of the list.
// Last->next = NULL, breaking the link from first in the list and becoming the last node.
// Second_to_last points to first, eventually being shift one above first node and being the second_to_last in the list.
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

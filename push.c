/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/04 13:45:13 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/16 18:18:04 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push:
//	pa - push a -		Pushes the first element of stack b and puts it to first element of stack a.
//	pb - push b -		Pushes the first element of stack a and puts it to first element of stack b.
// 						Do nothing if src is empty

// Target is the first element that'll be pushed to the other stack.
// If there's no destination, we will set it to top of dest stack and set its next to NULL.
// Otherwise it's added to the front of src stack.
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*target;

	if (!src)
		return ;
	target = *src;
	*src = (*src)->next;
	if (!dest)
	{
		*dest = target;
		(*dest)->next = NULL;
	}
	else
		add_front(dest, target);
}

void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/06 19:15:17 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/26 20:16:34 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function creates a new stack node with the value 'num' 
// and initializes the index to -1 to track its indexing status.
t_stack	*create_node(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = -1;
	new->next = NULL;
	return (new);
}

// This function links a new node (new) to the end of the stack. 
// If the stack is empty, the new node becomes the first node. 
// If not empty, the new node is appended to the end of the list.
void	link_to_end(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	else
	{
		temp = last_stack(*stack);
		temp->next = new;
		new->next = NULL;
	}
}

// Last_stack searches for the last position in stack.
t_stack	*last_stack(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// Add_front adds a certain stack to the first position of the stack.
void	add_front(t_stack **stack, t_stack *new)
{
	if (stack)
	{
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
}

int	count_stacks(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

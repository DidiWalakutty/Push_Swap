/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 19:11:19 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/24 12:49:16 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the minimum value among all un-indexed stacks.
// Checks if current > next and if it's indexed/unassigned or not.
// If so, current is bigger, so we set it to next since its value is smaller.
// If current is indexed, we set it to next. When we've done the whole stack and current == -1,
// we set its index to the current i, since it's the smallest value.
void	sort_index(t_stack **stack)
{
	t_stack	*start;
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	start = *stack;
	while (i < count_stacks(*stack))
	{
		start = *stack;
		while (start->next)
		{
			if (current->num > start->next->num && start->next->index == -1)
				current = start->next;
			else if (current->index != -1)
			{
				current = start->next;
			}
			start = start->next;
		}
		if (current->index == -1)
			current->index = i;
		current = *stack;
		i++;
	}
}

t_stack	*find_highest_node(t_stack *stack)
{
	t_stack	*highest_node;
	int		value;

	highest_node = stack;
	value = INT_MIN;
	while (stack)
	{
		if (stack->num > value)
		{
			value = stack->num;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

int	find_highest_num(t_stack *a)
{
	int		highest_num;
	t_stack	*temp;

	highest_num = INT_MIN;
	temp = a;
	while (temp)
	{
		if (temp->index > highest_num)
			highest_num = temp->index;
		temp = temp->next;
	}
	return (highest_num);
}

int	find_lowest_num(t_stack *stack)
{
	t_stack	*node;
	int		value;

	node = stack;
	value = node->num;
	while (node->next)
	{
		if (node->next->num < value)
			value = node->next->num;
		node = node->next;
	}
	return (value);
}

int	find_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		max_bits++;
	}
	return (max_bits);
}

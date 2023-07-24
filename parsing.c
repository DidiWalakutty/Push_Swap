/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 19:56:09 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/24 17:54:17 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if all arguments are digits. If strlen > 11, it's already be bigger than int max/min.
// Calls atoi to convert them to integers.
bool	check_digits(char *str, int *num)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 11)
		return (false);
	if (str[0] == '-')
	{
		if (!str[1])
			return (false);
		i++;
	}
	if (str[i] == '\0')
		exit_error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (atoi_and_overflow(str, num) == false)
		return (false);
	return (true);
}

// INT_MIN is -...648, INT_MAX is +...647, but in case of INT_MIN it won't become a negative, until multx with -1.
// At first it'll be +...648, so it overflows.
// the multx=1 check is in case the string is bigger that INT_MAX. It'll also automatically turn num in a negative (overflow).
bool	atoi_and_overflow(char *str, int *num)
{
	int	x;
	int	multx;

	*num = 0;
	x = 0;
	multx = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '-')
	{
		multx *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		*num += str[x] - '0';
		if (*num < 0 && (*num != INT_MIN || multx == 1))
			return (false);
		if (str[x + 1] >= '0' && str[x + 1] <= '9')
			*num *= 10;
		x++;
	}
	*num *= multx;
	return (true);
}

// This function parses the arguments are indeed digits and if it converts it from atoi.
// If so, it'll create and link them to create the stack.
bool	check_arguments(char **argv, t_stack **stack)
{
	int	i;
	int	num;

	i = 1;
	while (argv[i])
	{
		if (check_digits(argv[i], &num) == false)
			return (false);
		link_to_end(stack, create_node(num));
		i++;
	}
	return (true);
}

bool	repeated_found(t_stack **stack)
{
	t_stack	*copy;
	t_stack	*temp;

	copy = *stack;
	while (copy)
	{
		temp = copy->next;
		while (temp)
		{
			if (copy->num == temp->num)
				return (true);
			temp = temp->next;
		}
		copy = copy->next;
	}
	return (false);
}

// We check if the stack is already sorted by checking if the value of copy is > than the one next to it.
// If it's bigger, we know it isn't sorted, since it's not in ascending order.
bool	check_sorted(t_stack **stack)
{
	t_stack	*copy;
	t_stack	*temp;

	copy = *stack;
	while (copy && copy->next)
	{
		temp = copy->next;
		if (copy->num > temp->num)
			return (false);
		copy = copy->next;
	}
	return (true);
}

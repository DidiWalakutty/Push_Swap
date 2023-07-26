/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 19:56:09 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/26 19:21:16 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// This function converts a string to an integer 
// and checks for overflow. If the result is INT_MIN, 
// it uses multx to determine genuine overflow. 
// If multx is 1, it's an overflow, otherwise, it's INT_MAX.
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

// This function splits the arguments on the space char, 
// and checks for digits and converts them to an int.
// It'll create and link them to create the stack.
t_stack	*create_and_check(int argc, char **argv, t_stack **a)
{
	int		i;
	int		num;
	char	**arr;

	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (!arr || !arr[0])
			exit_error();
		if (check_digits(argv[i], &num) == false)
			exit_error();
		link_to_end(a, create_node(num));
		free_array(arr);
		i++;
	}
	return (*a);
}

// Checks if there's a repeated number.
// It holds on to 1 node, and compares it to all nodes after it.
// Sets the current node to the next one, and repeats the cycle.
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

// This functions checks if the stack is already sorted.
// It checks if the value of copy is > than next.
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

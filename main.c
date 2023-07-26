/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 22:07:12 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/26 18:55:00 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks()
{
	system("Leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	a = create_and_check(argc, argv, &a);
	b = NULL;
	if (repeated_found(&a) == true)
		exit_error();
	if (check_sorted(&a) == true)
		return (0);
	sort_index(&a);
	sort(&a, &b);
	free_stack(&a);
	system("Leaks push_swap");
	return (0);
}

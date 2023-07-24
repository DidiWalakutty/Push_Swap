/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 18:27:25 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/16 18:22:24 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_isdigit(int d);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putendl(char *s);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *s, int fd);

#endif
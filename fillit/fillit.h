/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:01:00 by thorker           #+#    #+#             */
/*   Updated: 2019/01/13 20:46:40 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

size_t	find_square(size_t number);
size_t	find_occupancy(char *field, size_t width);
void	print_field(char *field, size_t width);
void	brute_field(char *result);
char	*ft_rdch(char *file);
char	*free_result(char **result, int fd);
int		get_result(char **result, int place[4]);
void	print_result(char *result);
int		ft_check(int place[4]);
#endif

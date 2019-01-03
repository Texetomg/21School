/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:01:00 by thorker           #+#    #+#             */
/*   Updated: 2018/12/26 19:04:02 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>

char	**ft_rdch(char *file);
char	**free_result(char ***result, int fd);
int		get_result(char ***result, int place[4]);
void	print_result(char **result);
int		ft_check(int place[4]);
#endif

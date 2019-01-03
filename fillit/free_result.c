/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:26:18 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/12/29 13:49:01 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**free_result(char ***result, int fd)
{
	int	i;

	i = 0;
	close(fd);
	if (!result)
		return (0);
	while (*(*result + i) != 0)
	{
		ft_strdel(*result + i);
		i++;
	}
	free(*result);
	*result = NULL;
	return (0);
}

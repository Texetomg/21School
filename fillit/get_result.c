/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 13:56:54 by thorker           #+#    #+#             */
/*   Updated: 2018/12/29 17:08:14 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**remalloc_result(char ***result)
{
	int		i;
	char	**new_result;
	int		k;

	i = 0;
	while (*(*result + i) != 0)
		i++;
	new_result = (char**)malloc(sizeof(char*) * (i + 2));
	*(new_result + i + 1) = 0;
	k = -1;
	while (++k < i + 1)
		*(new_result + k) = (char*)malloc(sizeof(char) * 4);
	*(*(new_result + i)) = 'A' + i;
	i = 0;
	while (*(*result + i) != 0)
	{
		k = -1;
		while (++k < 4)
			*(*(new_result + i) + k) = *(*(*result + i) + k);
		i++;
	}
	free(*result);
	*result = new_result;
	return (*result + i);
}

int		get_result(char ***result, int place[4])
{
	int		index;
	char	**re_result;

	re_result = remalloc_result(result);
	if (ft_check(place) == 0)
		return (0);
	index = 0;
	while (index < 3)
	{
		(*re_result)[index + 1] = place[index + 1] - place[index];
		index++;
	}
	return (1);
}

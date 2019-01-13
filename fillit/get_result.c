/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 13:56:54 by thorker           #+#    #+#             */
/*   Updated: 2019/01/13 20:07:58 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*remalloc_result(char **result)
{
	int		i;
	char	*new_result;

	i = 0;
	while (*(*result + i) != 0)
		i++;
	new_result = (char*)malloc(sizeof(char) * (i + 5));
	*(new_result + i + 4) = 0;
	*(new_result + i) = 'A' + (i / 4);
	i = 0;
	while (*(*result + i) != 0)
	{
		*(new_result + i) = *(*result + i);
		i++;
	}
	free(*result);
	*result = new_result;
	return (*result + i);
}

int		get_result(char **result, int place[4])
{
	int		index;
	char	*re_result;

	if ((re_result = remalloc_result(result)) == NULL)
		return (0);
	if (ft_check(place) == 0)
		return (0);
	index = 0;
	while (index < 3)
	{
		re_result[index + 1] = place[index + 1] - place[index];
		index++;
	}
	return (1);
}

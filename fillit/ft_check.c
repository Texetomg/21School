/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 11:54:30 by thorker           #+#    #+#             */
/*   Updated: 2018/12/30 14:38:45 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		return_check(int ***y, int height)
{
	int i;

	if (y != NULL)
	{
		i = 0;
		while (i < height)
			free(*(*y + i++));
		free(*y);
		*y = NULL;
	}
	return (0);
}

int		**conv_to_array(int place[4])
{
	int **y;
	int i;
	int k;
	int height;

	height = -1;
	if ((y = (int**)malloc(sizeof(int*) * 4)) == NULL)
		return (0);
	while ((++height) < 4)
	{
		k = 0;
		i = -1;
		while (++i < 4)
			if (place[i] / 5 == height)
				k++;
		if ((*(y + height) = (int*)malloc(sizeof(int) * (k + 1))) == NULL)
			return (return_check(&y, height) == 0 ? NULL : y);
		*(*(y + height) + k) = 22;
		i = -1;
		k = 0;
		while (++i < 4)
			if (place[i] / 5 == height)
				*(*(y + height) + k++) = place[i] % 5;
	}
	return (y);
}

int		check_top_symb(int **y, int i)
{
	int k;
	int m;
	int correct;

	if (*(*(y + i)) != 22)
		correct = 0;
	else
		correct = 1;
	k = 0;
	while (*(*(y + i) + k) != 22)
	{
		m = 0;
		while (*(*(y + i - 1) + m) != 22)
		{
			if (*(*(y + i - 1) + m) == *(*(y + i) + k))
				correct = 1;
			m++;
		}
		k++;
	}
	if (correct == 0)
		return (0);
	return (1);
}

int		ft_check(int place[4])
{
	int i;
	int **y;
	int k;
	int flag;

	y = conv_to_array(place);
	i = 0;
	flag = 0;
	while (i < 4)
	{
		if (flag != 0)
			if (check_top_symb(y, i) == 0)
				return (return_check(&y, 4));
		k = -1;
		while (*(*(y + i) + (++k)) != 22)
		{
			flag = 1;
			if (*(*(y + i) + k) != *(*(y + i) + k + 1) - 1)
				if (*(*(y + i) + k + 1) != 22)
					return (return_check(&y, 4));
		}
		i++;
	}
	free(y);
	return (1);
}

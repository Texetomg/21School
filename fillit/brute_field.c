/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:36:40 by thorker           #+#    #+#             */
/*   Updated: 2019/01/13 20:51:47 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*new_field(size_t size)
{
	char	*field;
	size_t	i;

	if ((field = (char*)malloc(sizeof(char) * (size * size))) == 0)
		return (0);
	i = 0;
	while (i < size * size)
		*(field + i++) = '.';
	return (field);
}

int		fill_field(char *field, char *result, size_t place, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (*(field + place) != '.')
			return (0);
		*(field + place) = *result;
		if (i == 3)
			return (1);
		if (*(result + i + 1) == 1 && place % size != size - 1)
			place++;
		else if ((*(result + i + 1) == 3)
				&& (place % size > 1) && (place / size < size - 1))
			place = place + size - 2;
		else if ((*(result + i + 1) == 4)
				&& (place % size > 0) && (place / size < size - 1))
			place = place + size - 1;
		else if ((*(result + i + 1) == 5) && (place / size < size - 1))
			place = place + size;
		else
			return (0);
		i++;
	}
	return (0);
}

void	back_fill(char *field, char *result, size_t place, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (*(field + place) != *result)
			return ;
		*(field + place) = '.';
		if (i == 3)
			return ;
		if (*(result + i + 1) == 1 && place % size != size - 1)
			place++;
		else if ((*(result + i + 1) == 3)
				&& (place % size > 1) && (place / size < size - 1))
			place = place + size - 2;
		else if ((*(result + i + 1) == 4)
				&& (place % size > 0) && (place / size < size - 1))
			place = place + size - 1;
		else if ((*(result + i + 1) == 5) && (place / size < size - 1))
			place = place + size;
		else
			return ;
		i++;
	}
}

int		check_field(char *field, char *result, size_t size)
{
	size_t	place;

	place = 0;
	if (*result != 0)
	{
		while (place < size * size)
		{
			if (fill_field(field, result, place, size) != 0)
			{
				if (check_field(field, result + 4, size) == 1)
					return (1);
			}
			back_fill(field, result, place, size);
			place++;
		}
	}
	else
		return (1);
	return (0);
}

void	brute_field(char *result)
{
	size_t	i;
	char	*field;
	size_t	size;

	i = 0;
	while (*(result + i) != 0)
		i++;
	size = find_square(i);
	field = new_field(size);
	check_field(field, result, size);
	while (find_occupancy(field, size) == 0)
	{
		size++;
		free(field);
		field = new_field(size);
		check_field(field, result, size);
	}
	print_field(field, size);
}

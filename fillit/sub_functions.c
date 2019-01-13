/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:54:57 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/13 19:53:57 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	find_square(size_t number)
{
	size_t result;

	result = 0;
	while ((result * result) < number)
		result++;
	return (result);
}

void	print_field(char *field, size_t width)
{
	size_t i;
	size_t flag;

	flag = 0;
	i = 0;
	while (i < width * width)
	{
		ft_putchar(*(field + i));
		i++;
		flag++;
		if (flag == width)
		{
			ft_putchar('\n');
			flag = 0;
		}
	}
}

size_t	find_occupancy(char *field, size_t width)
{
	size_t i;
	size_t size;

	size = 0;
	i = 0;
	while (i < width * width)
	{
		if (*(field + i) != '.')
		{
			if (i / width > size)
				size = i / width;
			if (i % width > size)
				size = i % width;
		}
		i++;
	}
	return (size);
}

char	*free_result(char **result, int fd)
{
	if (fd != -1)
		close(fd);
	if (!result)
		return (0);
	ft_strdel(result);
	result = NULL;
	return (0);
}

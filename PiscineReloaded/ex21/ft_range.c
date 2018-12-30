/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:01 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/20 12:18:02 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*buffer;
	int	index;

	index = 0;
	if (min >= max)
		return (0);
	buffer = (int*)malloc(sizeof(*buffer) * (max - min + 1));
	while (min < max)
	{
		buffer[index] = min;
		min++;
		index++;
	}
	return (buffer);
}

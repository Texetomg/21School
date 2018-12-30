/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:11:27 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/20 12:11:32 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		length;
	char	*buffer;
	int		index;

	index = 0;
	length = 0;
	while (src[length])
		length++;
	buffer = (char*)malloc(sizeof(*buffer) * (length + 1));
	while (index < length)
	{
		buffer[index] = src[index];
		index++;
	}
	buffer[length] = '\0';
	return (buffer);
}

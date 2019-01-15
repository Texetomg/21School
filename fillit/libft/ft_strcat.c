/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:33:50 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/23 17:33:52 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;

	index = 0;
	while (s1[index])
		index++;
	while (*s2)
	{
		s1[index++] = *s2;
		s2++;
	}
	s1[index] = '\0';
	return (s1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:30:06 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/20 13:30:08 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	index;
	int	counter;

	counter = 0;
	index = 0;
	while (tab[index] != '\0')
	{
		if (f(tab[index]))
			counter++;
		index++;
	}
	return (counter);
}

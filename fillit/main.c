/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:34:48 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/12/29 17:13:05 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "error\n", 6);
		return (0);
	}
	print_result(ft_rdch(av[1]));
	return (0);
}

void	print_result(char **result)
{
	int i;
	int k;

	if (result == 0)
	{
		write(2, "error\n", 6);
		return ;
	}
	if (*result == 0)
		ft_putstr("This is empty\n");
	i = 0;
	while (*(result + i) != 0)
	{
		ft_putchar(**(result + i));
		k = 0;
		while (++k < 4)
			ft_putchar(*(*(result + i) + k) + '0');
		ft_putchar('\n');
		i++;
	}
}

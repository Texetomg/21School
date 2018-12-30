/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_recursive_factorial.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:27:18 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/19 17:40:12 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int result;

	result = 1;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0 || nb >= 13)
	{
		return (0);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

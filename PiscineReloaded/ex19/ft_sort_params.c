/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:27:18 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/19 17:40:12 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if ((s1[index] < s2[index]) || (s1[index] > s2[index]))
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

int		main(int argc, char **argv)
{
	int counter;
	int index_argv;

	counter = 1;
	while (counter < argc)
	{
		index_argv = counter + 1;
		while (argc > index_argv)
		{
			if (ft_strcmp(argv[counter], argv[index_argv]) > 0)
				ft_swap(&argv[counter], &argv[index_argv]);
			index_argv++;
		}
		counter++;
	}
	counter = 1;
	while (counter < argc)
	{
		ft_putstr(argv[counter]);
		ft_putchar('\n');
		counter++;
	}
	return (0);
}

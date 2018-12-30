/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:24:07 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/20 14:24:08 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display_file(char *obj)
{
	char	buffer;
	int		file;

	file = open(obj, O_RDONLY);
	if (file < 0)
		return ;
	while (read(file, &buffer, 1))
		write(1, &buffer, 1);
	close(file);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display_file(argv[1]);
	return (0);
}

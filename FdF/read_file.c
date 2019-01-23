/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:14:31 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/23 15:15:49 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*read_file(char *file, void *mlx_ptr, void *win_ptr)
{
	int		fd;
	t_list	*list;
	char	*line;
	char	**split_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	list = ft_lstnew("0", sizeof(t_point));
	init_list(mlx_ptr, win_ptr, list);
	while (get_next_line(fd, &line))
	{
		LIST->x = -1;
		split_line = ft_strsplit(line, ' ');
		LIST->y++;
		while (*split_line)
		{
			LIST->x++;
			LIST->z = atoi(*split_line);
			ft_lstadd(&list, ft_lstnew(list->content, sizeof(t_point)));
			split_line++;
		}
	}
	close(fd);
	return (list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:14:31 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/20 19:32:10 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void    init_list(void *mlx_ptr, void *win_ptr, t_list *list)
{
    ((t_point*)(list->content))->x = -1;
    ((t_point*)(list->content))->y = -1;
    ((t_point*)(list->content))->z = 0;
    ((t_point*)(list->content))->mlx_ptr = mlx_ptr;
    ((t_point*)(list->content))->win_ptr = win_ptr;
}

t_list    *read_file(char *file, void *mlx_ptr, void *win_ptr)
{
    int     fd;
    t_list  *c_list;
    char    *line;
    char    **split_line;
   
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        write(1, "bad fd", 6);
        return (0);
    }
    c_list = ft_lstnew("0", sizeof(t_point));
    init_list(mlx_ptr, win_ptr, c_list);
    while (get_next_line(fd, &line))
    {
        ((t_point*)(c_list->content))->x = -1;
        split_line = ft_strsplit(line, ' ');
        ((t_point*)(c_list->content))->y++;
        while (*split_line)
        {
            ((t_point*)(c_list->content))->x++;
            ((t_point*)(c_list->content))->z = atoi(*split_line);
            ft_lstadd(&c_list, ft_lstnew(c_list->content, sizeof(t_point)));
            split_line++;
        }
    }
    close(fd);
    return (c_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:14:31 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 18:36:38 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void    init_list(void *mlx_ptr, void *win_ptr, t_list *list)
{
    ((t_point*)(list->content))->x = -1;
    ((t_point*)(list->content))->y = -1;
    ((t_point*)(list->content))->z = 0;
    ((t_point*)(list->content))->size = 1;
    ((t_point*)(list->content))->x_step = 50;
    ((t_point*)(list->content))->y_step = 50;
    ((t_point*)(list->content))->alf = 0.1;
    ((t_point*)(list->content))->bet = 0.1;
    ((t_point*)(list->content))->gam = 0.1;
    ((t_point*)(list->content))->x_curr = 0;
    ((t_point*)(list->content))->y_curr = 0;
    ((t_point*)(list->content))->z_curr = 0;
    ((t_point*)(list->content))->x_pos = -1;
    ((t_point*)(list->content))->y_count = 0;
    ((t_point*)(list->content))->mlx = mlx_ptr;
    ((t_point*)(list->content))->win = win_ptr;
}

void    add_sub_coords(t_list **list)
{
    t_list  *sub_list;
    int     y_count;
    int     x_pos;

    y_count = 0;
    x_pos = 0;
    sub_list = *list; 
        
    while (sub_list->next)
    {
        ((t_point*)(sub_list->content))->x_curr = ((t_point*)(sub_list->content))->x;
        ((t_point*)(sub_list->content))->y_curr = ((t_point*)(sub_list->content))->y; 
        ((t_point*)(sub_list->content))->z_curr = ((t_point*)(sub_list->content))->z;   
        ((t_point*)(sub_list->content))->y_count = y_count;
        ((t_point*)(sub_list->content))->x_pos = x_pos;
        if (((t_point*)(sub_list->content))->x  > ((t_point*)(sub_list->next->content))->x)
        {
            y_count++;
            x_pos = -1;
        }
        x_pos++;  
         
        sub_list = sub_list->next;
    }
}

t_list    *read_file(char *file, void *mlx_ptr, void *win_ptr)
{
    int     fd;
    t_list  *c_list;
    char    *line;
    char    **split_line;
   
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
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

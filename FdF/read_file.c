/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:14:31 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 20:08:30 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void    init_list(void *mlx_ptr, void *win_ptr, t_list *list)
{
    LIST->x = -1;
    LIST->y = -1;
    LIST->z = 0;
    LIST->size = 3;
    LIST->x_step = 50;
    LIST->y_step = 50;
    LIST->alf = 0.1;
    LIST->bet = 0.1;
    LIST->gam = 0.1;
    LIST->x_curr = 0;
    LIST->y_curr = 0;
    LIST->z_curr = 0;
    LIST->x_pos = -1;
    LIST->y_count = 0;
    LIST->mlx = mlx_ptr;
    LIST->win = win_ptr;
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
        SUB_LIST->x_curr = SUB_LIST->x;
        SUB_LIST->y_curr = SUB_LIST->y; 
        SUB_LIST->z_curr = SUB_LIST->z;   
        SUB_LIST->y_count = y_count;
        SUB_LIST->x_pos = x_pos;
        if (SUB_LIST->x  > SUB_LIST_N->x)
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
    t_list  *list;
    char    *line;
    char    **split_line;
   
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

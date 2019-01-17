/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:14:31 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/17 16:56:04 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

t_list    *read_file(char *file)
{
    int     fd;
    t_list  *coord_list;
    int     coord_point[3];
    char    *line;
    char    **sub_line;
    t_list  *ptr_start;

    fd = open(file, O_RDONLY);
    coord_list = ft_lstnew(coord_point, 3);
    ptr_start = coord_list;
    coord_point[1] = -1;
    while(get_next_line(fd, &line))
    {
        coord_point[0] = -1;
        coord_point[1]++;
        sub_line = ft_strsplit(line, ' ');
        while (*(sub_line + ++coord_point[0]))
        {
            coord_point[2] = ft_atoi(*sub_line);
            coord_list->content = coord_point;
        }
        ft_lstadd(&coord_list, ft_lstnew(coord_point, 3));
    }
    return (*ptr_start);
}

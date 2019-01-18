/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:14:31 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/18 15:26:04 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void    zero_list(t_list *list)
{
    ((int*)(list->content))[0] = -1;
	((int*)(list->content))[1] = -1;
	((int*)(list->content))[2] = 0;
}

t_list    *read_file(char *file)
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
    c_list = ft_lstnew("0", 3 * sizeof(int));
    zero_list(c_list);
    while (get_next_line(fd, &line))
    {
        ((int*)(c_list->content))[0] = -1;
        split_line = ft_strsplit(line, ' ');
        ((int*)(c_list->content))[1]++;
        while (*split_line)
        {
            ((int*)(c_list->content))[0]++;
            ((int*)(c_list->content))[2] = atoi(*split_line);
            ft_lstadd(&c_list, ft_lstnew(c_list->content, 3 * sizeof(int)));
            split_line++;
        }
    }
    close(fd);
    return (c_list);
}

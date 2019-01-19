/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:29:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/19 17:11:32 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bresenham_original(t_list *list, void *mlx_ptr, void *win_ptr)
{
    int deltax;
	int error;
	int coord[4];
	int diry;

	coord[0] = ((int*)(list->content))[0];
	coord[1] = ((int*)(list->content))[1];
	coord[2] = ((int*)(list->next->content))[0];
	coord[3] = ((int*)(list->next->content))[1];
	deltax = ft_absolute(coord[2] - coord[0]);
	error = 0;
	diry = ((coord[3] - coord[1]) > 0)? 1: -1;
	while(coord[0] <= coord[2])
	{
		mlx_pixel_put(mlx_ptr, win_ptr, coord[0], coord[1], 0xFFFFFF);
		error = error + ft_absolute(coord[3] - coord[1]);
		if (2 * error >= deltax)
		{
			coord[1] = coord[1] + diry;
			error = error - deltax;
		}
		coord[0]++;
	}
}


t_list *drow_line(t_list *list, void *mlx_ptr, void *win_ptr)
{
	t_list	*sub;
	ft_lstreverse(&list);
	
	sub = list;
	while (sub->next)
	{
		((int*)(sub->next->content))[0] = ((int*)(sub->next->content))[0] * 10;
		((int*)(sub->next->content))[1] = ((int*)(sub->next->content))[1] * 10;
		((int*)(sub->next->content))[2] = ((int*)(sub->next->content))[2] * 10;
    	bresenham_original(sub, mlx_ptr, win_ptr);
		sub = sub->next;
	}
	return(list);

}
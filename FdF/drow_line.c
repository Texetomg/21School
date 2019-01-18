/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:29:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/18 16:58:49 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bresenham_original(t_list *list, void *mlx_ptr, void *win_ptr)
{
    int deltax;
	int error;
	int y;
	int diry;

	deltax = ft_absolute(x1 - x0);
	error = 0;
	y = y0;
	diry = ((y1 - y0) > 0)? 1: -1;
	while(x0 <= x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFFFFFF);
		error = error + ft_absolute(y1 - y0);
		if (2 * error >= deltax)
		{
			y0 = y0 + diry;
			error = error - deltax;
		}
		x0++;
	}
}

void drow_line(t_list *list, void *mlx_ptr, void *win_ptr)
{
	ft_lstreverse(&list);
	while(list->next)
	{
    	bresenham_original(list, mlx_ptr, win_ptr);
		list = list->next;
	}
}
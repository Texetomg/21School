/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_change_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:01:27 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 20:24:18 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_move_x(t_list *list, int step)
{
	((t_point*)(list->content))->x += step;
	while (list->next)
	{
		((t_point*)(list->next->content))->x += step;
		list = list->next;
	}
}

void	img_move_y(t_list *list, int step)
{
	((t_point*)(list->content))->y += step;
	while (list->next)
	{
		((t_point*)(list->next->content))->y += step;
		list = list->next;
	}
}

void	img_rotate_x(t_list *list, double angle)
{
	int y;
	int z;

	while (list->next)
	{
		y = ((t_point*)(list->content))->y;
		z = ((t_point*)(list->content))->z;
		((t_point*)(list->content))->y_scale += (y * cos(angle)) + (z * sin(angle));
		((t_point*)(list->content))->z_scale += (-y * sin(angle)) + (z * cos(angle));
		list = list->next;
	}
}

void	img_rotate_y(t_list *list, double angle)
{
	int x;
	int z;

	while (list->next)
	{
		x = ((t_point*)(list->content))->x;
		z = ((t_point*)(list->content))->z;
		((t_point*)(list->content))->x_scale += (x * cos(angle)) + (z * sin(angle));
		((t_point*)(list->content))->z_scale += (-x * sin(angle)) + (z * cos(angle));
		list = list->next;
	}
}

void	img_rotate_z(t_list *list, double angle)
{
	int x;
	int y;

	while (list->next)
	{
		x = ((t_point*)(list->content))->x;
		y = ((t_point*)(list->content))->y;
		((t_point*)(list->content))->x_scale = (x * cos(angle)) - (y * sin(angle));
		((t_point*)(list->content))->y_scale = (x * sin(angle)) + (y * cos(angle));
		list = list->next;
	}
}

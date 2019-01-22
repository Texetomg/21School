/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_change_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:01:27 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 18:33:31 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_move_x(t_list *list, int step)
{
	((t_point*)(list->content))->x_step += step;
	while (list->next)
	{
		((t_point*)(list->next->content))->x_step += step;
		list = list->next;
	}
}

void	img_move_y(t_list *list, int step)
{
	((t_point*)(list->content))->y_step += step;
	while (list->next)
	{
		((t_point*)(list->next->content))->y_step += step;
		list = list->next;
	}
}

void	img_rotate_x(t_list *list, double angle)
{
	((t_point*)(list->content))->alf += angle;
	while (list->next)
	{	
		((t_point*)(list->content))->alf += angle;
			list = list->next;
	}
}

void	img_rotate_y(t_list *list, double angle)
{
	((t_point*)(list->content))->bet += angle;
	while (list->next)
	{
		((t_point*)(list->next->content))->bet += angle;
		list = list->next;
	}	
}

void	img_rotate_z(t_list *list, double angle)
{
	((t_point*)(list->content))->gam += angle;
	while (list->next)
	{
		((t_point*)(list->next->content))->gam += angle;
		list = list->next;
	}
}

void		rotation_matrix(t_list *list, int *arr)
{
	int 	x;
	int 	y;
	int		z;
	
	x = arr[0];
	y = arr[1];
	z = arr[2];
	arr[0] = cos(BET) * cos(GAM) * x - cos(BET) * sin(GAM) * y + sin(BET) * z;
	arr[1] = sin(ALF) * sin(BET) * cos(GAM) + cos(ALF) *sin(GAM) * x - 
			sin(ALF) * sin(BET) * sin(GAM) + cos(ALF) * cos(GAM) * y - sin(ALF) * cos(BET) * z;
	x = arr[3];
	y = arr[4];
	z = arr[5];
	arr[3] = cos(BET) * cos(GAM) * x - cos(BET) * sin(GAM) * y + sin(BET) * z;
	arr[4] = sin(ALF) * sin(BET) * cos(GAM) + cos(ALF) *sin(GAM) * x - 
			sin(ALF) * sin(BET) * sin(GAM) + cos(ALF) * cos(GAM) * y - sin(ALF) * cos(BET) * z;
}
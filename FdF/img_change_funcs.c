/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_change_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:01:27 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 20:08:29 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_move_x(t_list *list, int step)
{
	LIST->x_step += step;
	while (list->next)
	{
		LIST_N->x_step += step;
		list = list->next;
	}
}

void	img_move_y(t_list *list, int step)
{
	LIST->y_step += step;
	while (list->next)
	{
		LIST_N->y_step += step;
		list = list->next;
	}
}

void	img_rotate_x(t_list *list, double angle)
{
	LIST->alf += angle;
	while (list->next)
	{	
		LIST_N->alf += angle;
			list = list->next;
	}
}

void	img_rotate_y(t_list *list, double angle)
{
	LIST->bet += angle;
	while (list->next)
	{
		LIST_N->bet += angle;
		list = list->next;
	}	
}

void	img_rotate_z(t_list *list, double angle)
{
	LIST->gam += angle;
	while (list->next)
	{
		LIST_N->gam += angle;
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
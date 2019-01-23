/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:01:27 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/23 14:19:53 by bfalmer-         ###   ########.fr       */
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

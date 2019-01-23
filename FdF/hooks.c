/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:30:09 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/23 17:25:41 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel(t_list *list)
{
	while (list->next)
	{
		LIST->alf = 0;
		LIST->bet = 0;
		LIST->gam = 0;
		list = list->next;
	}
}

void	iso(t_list *list)
{
	while (list->next)
	{
		LIST->alf = 0.07;
		LIST->bet = -0.05;
		LIST->gam = 0.73;
		list = list->next;
	}
}

void	which_func(int key, t_list *list)
{
	if (key == 69)
		img_resize(list, 1.1);
	if (key == 78)
		img_resize(list, 0.9);
	if (key == 123)
		img_move_x(list, -10);
	if (key == 124)
		img_move_x(list, 10);
	if (key == 125)
		img_move_y(list, 10);
	if (key == 126)
		img_move_y(list, -10);
	if (key == 91)
		img_rotate_x(list, TETA);
	if (key == 84)
		img_rotate_x(list, -TETA);
	if (key == 86)
		img_rotate_y(list, TETA);
	if (key == 88)
		img_rotate_y(list, -TETA);
	if (key == 89)
		img_rotate_z(list, TETA);
	if (key == 85)
		img_rotate_z(list, -TETA);
}

int		deal_key(int key, t_list *list)
{
	t_list	*sub;

	if (key == 53)
		exit(0);
	if (key == 34)
		iso(list);
	if (key == 35)
		parallel(list);
	mlx_clear_window(LIST->mlx, LIST->win);
	sub = list;
	which_func(key, sub);
	set_help(list);
	img_draw(list);
	return (0);
}

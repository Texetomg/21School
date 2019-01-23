/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:18:58 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/23 17:25:41 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_matrix(t_list *list, int *arr)
{
	int	x;
	int	y;
	int	z;

	x = arr[0];
	y = arr[1];
	z = arr[2];
	arr[0] = cos(BET) * cos(GAM) * x - cos(BET) * sin(GAM) * y + sin(BET) * z;
	arr[1] = sin(ALF) * sin(BET) * cos(GAM) + cos(ALF) * sin(GAM) * x -
			sin(ALF) * sin(BET) * sin(GAM) + cos(ALF) * cos(GAM) * y -
			sin(ALF) * cos(BET) * z;
	x = arr[3];
	y = arr[4];
	z = arr[5];
	arr[3] = cos(BET) * cos(GAM) * x - cos(BET) * sin(GAM) * y + sin(BET) * z;
	arr[4] = sin(ALF) * sin(BET) * cos(GAM) + cos(ALF) * sin(GAM) * x -
			sin(ALF) * sin(BET) * sin(GAM) + cos(ALF) * cos(GAM) * y -
			sin(ALF) * cos(BET) * z;
}

void	init_list(void *mlx_ptr, void *win_ptr, t_list *list)
{
	LIST->x = -1;
	LIST->y = -1;
	LIST->z = 0;
	LIST->size = 3;
	LIST->x_step = 50;
	LIST->y_step = 50;
	LIST->alf = 0;
	LIST->bet = 0;
	LIST->gam = 0;
	LIST->x_curr = 0;
	LIST->y_curr = 0;
	LIST->z_curr = 0;
	LIST->x_pos = -1;
	LIST->y_count = 0;
	LIST->mlx = mlx_ptr;
	LIST->win = win_ptr;
}

void	add_sub_coords(t_list **list)
{
	t_list	*sub_list;
	int		y_count;
	int		x_pos;

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
		if (SUB_LIST->x > SUB_LIST_N->x)
		{
			y_count++;
			x_pos = -1;
		}
		x_pos++;
		sub_list = sub_list->next;
	}
}

void	set_help(t_list *list)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = LIST->mlx;
	win = LIST->win;
	mlx_string_put(mlx, win, 1000, y += 35, 0x00FF00, "Zoom: +/-");
	mlx_string_put(mlx, win, 1000, y += 30, 0x00FF00, "Move: Arrows");
	mlx_string_put(mlx, win, 1000, y += 25, 0x00FF00, "X: 2/8");
	mlx_string_put(mlx, win, 1000, y += 25, 0x00FF00, "Y: 4/6");
	mlx_string_put(mlx, win, 1000, y += 25, 0x00FF00, "Z: 3/7");
	mlx_string_put(mlx, win, 1000, y += 25, 0x00FF00, "ISO: I Key");
	mlx_string_put(mlx, win, 1000, y += 25, 0x00FF00, "Parallel: P Key");
}

void	img_resize(t_list *list, double size)
{
	LIST->size *= size;
	while (list->next)
	{
		LIST_N->size *= size;
		list = list->next;
	}
}

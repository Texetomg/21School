/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:29:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 20:10:22 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(void *mlx_ptr, void *win_ptr, int *arr)
{
    int deltaX = ft_absolute(arr[3] - arr[0]);
    int deltaY = ft_absolute(arr[4] - arr[1]);
    int error = deltaX - deltaY;
	int error2;
	
    mlx_pixel_put(mlx_ptr, win_ptr, arr[3], arr[4], 0x00FF00);
    while(arr[0] != arr[3] || arr[1] != arr[4]) 
   	{
	
        mlx_pixel_put(mlx_ptr, win_ptr, arr[0], arr[1], 0x00FF00);
        error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            arr[0] += arr[0] < arr[3] ? 1 : -1;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            arr[1] += arr[1] < arr[4] ? 1 : -1;
        }
    }
}

void	fill_vert_coord_array(t_list *list, t_list *sub_list, int *arr)
{
	arr[0] = LIST->x_curr * LIST->size + LIST->x_step;
	arr[1] = LIST->y_curr * LIST->size + LIST->y_step;
	arr[2] = LIST->z_curr * LIST->size;
	arr[3] = SUB_LIST->x_curr * LIST->size + LIST->x_step;
	arr[4] = SUB_LIST->y_curr * LIST->size + LIST->y_step;
	arr[5] = SUB_LIST->z_curr * LIST->size;
}

void	fill_horiz_coord_array(t_list *list, int *arr)
{
	arr[0] = LIST->x_curr * LIST->size + LIST->x_step;
	arr[1] = LIST->y_curr * LIST->size + LIST->y_step;
	arr[2] = LIST->z_curr * LIST->size;
	arr[3] = LIST_N->x_curr * LIST->size + LIST->x_step;
	arr[4] = LIST_N->y_curr * LIST->size + LIST->y_step;
	arr[5] = LIST_N->z_curr * LIST->size;
}

void	draw_vert(t_list *sub_list, t_list *sec_sub,int *arr)
{	
	fill_vert_coord_array(sub_list, sec_sub, arr);
	rotation_matrix(sub_list, arr);
	bresenham(SUB_LIST->mlx, SUB_LIST->win, arr);
	sec_sub = sec_sub->next;
	sub_list = sub_list->next;
} 

void	img_draw(t_list *list)
{
	t_list	*sub_list;
	t_list	*sec_sub;
	int		out_arr[6];

	sub_list = list;
	while (sub_list->next)
	{
		fill_horiz_coord_array(sub_list, out_arr);
		rotation_matrix(sub_list, out_arr);
		if (SUB_LIST->x_pos  < SUB_LIST_N->x_pos)
			bresenham(SUB_LIST->mlx, SUB_LIST->win, out_arr);
		sub_list = sub_list->next;
	}
	sub_list = list;
	sec_sub = list;
	while (SEC_SUB->y_count == SUB_LIST->y_count)	
			sec_sub = sec_sub->next;
			
	while (sec_sub->next)
	{		
		draw_vert(sub_list, sec_sub, out_arr);
		while (SEC_SUB_N->x_pos > SUB_LIST_N->x_pos)
			sec_sub = sec_sub->next;
		while (SEC_SUB_N->x_pos < SUB_LIST_N->x_pos)
			sub_list = sub_list->next;
		draw_vert(sub_list, sec_sub, out_arr);
		sec_sub = sec_sub->next;
		sub_list = sub_list->next;
	}
}

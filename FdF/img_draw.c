/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:29:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 19:46:08 by bfalmer-         ###   ########.fr       */
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
	arr[0] = ((t_point*)(list->content))->x_curr * ((t_point*)(list->content))->size + ((t_point*)(list->content))->x_step;
	arr[1] = ((t_point*)(list->content))->y_curr * ((t_point*)(list->content))->size + ((t_point*)(list->content))->y_step;
	arr[2] = ((t_point*)(list->content))->z_curr * ((t_point*)(list->content))->size;
	arr[3] = ((t_point*)(sub_list->content))->x_curr * ((t_point*)(list->content))->size + ((t_point*)(list->content))->x_step;
	arr[4] = ((t_point*)(sub_list->content))->y_curr * ((t_point*)(list->content))->size + ((t_point*)(list->content))->y_step;
	arr[5] = ((t_point*)(sub_list->content))->z_curr * ((t_point*)(list->content))->size;
}

void	fill_horiz_coord_array(t_list *list, int *arr)
{
	arr[0] = ((t_point*)(list->content))->x_curr * ((t_point*)(list->content))->size + ((t_point*)(list->content))->x_step;
	arr[1] = ((t_point*)(list->content))->y_curr * ((t_point*)(list->content))->size + ((t_point*)(list->content))->y_step;
	arr[2] = ((t_point*)(list->content))->z_curr * ((t_point*)(list->content))->size;
	arr[3] = ((t_point*)(list->next->content))->x_curr * ((t_point*)(list->content))->size + ((t_point*)(list->content))->x_step;
	arr[4] = ((t_point*)(list->next->content))->y_curr * ((t_point*)(list->content))->size + ((t_point*)(list->content))->y_step;
	arr[5] = ((t_point*)(list->next->content))->z_curr * ((t_point*)(list->content))->size;
}

void	draw_vert(t_list *sub_list, t_list *sec_sub,int *arr)
{	
	fill_vert_coord_array(sub_list, sec_sub, arr);
	rotation_matrix(sub_list, arr);
	bresenham(((t_point*)(sub_list->content))->mlx, ((t_point*)(sub_list->content))->win, arr);
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
		if (((t_point*)(sub_list->content))->x_pos  < ((t_point*)(sub_list->next->content))->x_pos)
			bresenham(((t_point*)(sub_list->content))->mlx, ((t_point*)(sub_list->content))->win, out_arr);
		sub_list = sub_list->next;
	}
	sub_list = list;
	sec_sub = list;
	while (((t_point*)(sec_sub->content))->y_count == ((t_point*)(sub_list->content))->y_count)	
			sec_sub = sec_sub->next;
			
	while (sec_sub->next)
	{		
		draw_vert(sub_list, sec_sub, out_arr);
		while (((t_point*)(sec_sub->next->content))->x_pos > ((t_point*)(sub_list->next->content))->x_pos)
			sec_sub = sec_sub->next;
		while (((t_point*)(sec_sub->next->content))->x_pos < ((t_point*)(sub_list->next->content))->x_pos)
			sub_list = sub_list->next;
		draw_vert(sub_list, sec_sub, out_arr);
		sec_sub = sec_sub->next;
		sub_list = sub_list->next;
	}
}

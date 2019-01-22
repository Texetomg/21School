/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:29:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 18:31:05 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(void *mlx_ptr, void *win_ptr, int *arr)
{
    int deltaX = ft_absolute(arr[3] - arr[0]);
    int deltaY = ft_absolute(arr[4] - arr[1]);
    int error = deltaX - deltaY;
	int error2;
	
    mlx_pixel_put(mlx_ptr, win_ptr, arr[3], arr[4], 0xFFFFFF);
    while(arr[0] != arr[3] || arr[1] != arr[4]) 
   	{
	
        mlx_pixel_put(mlx_ptr, win_ptr, arr[0], arr[1], 0xFFFFFF);
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

void draw_vert(t_list *sub, t_list *sec_sub,int *arr)
{	
	arr[0] = ((t_point*)(sub->content))->x_curr * ((t_point*)(sub->content))->size + ((t_point*)(sub->content))->x_step;
	arr[1] = ((t_point*)(sub->content))->y_curr * ((t_point*)(sub->content))->size + ((t_point*)(sub->content))->y_step;
	arr[2] = ((t_point*)(sub->content))->z_curr * ((t_point*)(sub->content))->size;
	arr[3] = ((t_point*)(sec_sub->content))->x_curr * ((t_point*)(sub->content))->size + ((t_point*)(sub->content))->x_step;
	arr[4] = ((t_point*)(sec_sub->content))->y_curr * ((t_point*)(sub->content))->size + ((t_point*)(sub->content))->y_step;
	arr[5] = ((t_point*)(sec_sub->content))->z_curr * ((t_point*)(sub->content))->size;
	rotation_matrix(sub, arr);
	bresenham(((t_point*)(sub->content))->mlx, ((t_point*)(sub->content))->win, arr);
	sec_sub = sec_sub->next;
	sub = sub->next;
} 

void	img_draw(t_list *list)
{
	t_list	*sub;
	t_list	*sec_sub;
	int		out_arr[6];
	sub = list;
	
	while (sub->next)
	{
		out_arr[0] = ((t_point*)(sub->content))->x_curr * ((t_point*)(sub->content))->size + ((t_point*)(sub->content))->x_step;
		out_arr[1] = ((t_point*)(sub->content))->y_curr * ((t_point*)(sub->content))->size + ((t_point*)(sub->content))->y_step;
		out_arr[2] = ((t_point*)(sub->content))->z_curr * ((t_point*)(sub->content))->size;
		out_arr[3] = ((t_point*)(sub->next->content))->x_curr * ((t_point*)(sub->content))->size + ((t_point*)(sub->content))->x_step;
		out_arr[4] = ((t_point*)(sub->next->content))->y_curr * ((t_point*)(sub->content))->size + ((t_point*)(sub->content))->y_step;
		out_arr[5] = ((t_point*)(sub->next->content))->z_curr * ((t_point*)(sub->content))->size;
		rotation_matrix(sub, out_arr);
		if (((t_point*)(sub->content))->x_pos  < ((t_point*)(sub->next->content))->x_pos)
			bresenham(((t_point*)(sub->content))->mlx, ((t_point*)(sub->content))->win, out_arr);
		sub = sub->next;
	}
	sub = list;
	sec_sub = list;
	while (((t_point*)(sec_sub->content))->y_count == ((t_point*)(sub->content))->y_count)	
			sec_sub = sec_sub->next;
			
	while (sec_sub->next)
	{		
		draw_vert(sub, sec_sub, out_arr);
		while (((t_point*)(sec_sub->next->content))->x_pos > ((t_point*)(sub->next->content))->x_pos)
			sec_sub = sec_sub->next;
		while (((t_point*)(sec_sub->next->content))->x_pos < ((t_point*)(sub->next->content))->x_pos)
			sub = sub->next;
		draw_vert(sub, sec_sub, out_arr);
		sec_sub = sec_sub->next;
		sub = sub->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:29:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 21:49:38 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(void *mlx_ptr, void *win_ptr, int arr[])
{
    int deltaX = ft_absolute(arr[2] - arr[0]);
    int deltaY = ft_absolute(arr[3] - arr[1]);
    int error = deltaX - deltaY;
	int error2;
    mlx_pixel_put(mlx_ptr, win_ptr, arr[2], arr[3], 0xFFFFFF);
    while(arr[0] != arr[2] || arr[1] != arr[3]) 
   	{
	
        mlx_pixel_put(mlx_ptr, win_ptr, arr[0], arr[1], 0xFFFFFF);
        error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            arr[0] += arr[0] < arr[2] ? 1 : -1;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            arr[1] += arr[1] < arr[3] ? 1 : -1;
        }
    }
}

void draw_vert(t_list *sub, t_list *sec_sub)
{
	t_list	*res_sub;
	int	out_arr[4];
	res_sub = ft_lstnew("0", sizeof(t_point));
	ft_lstadd(&res_sub, ft_lstnew("0", sizeof(t_point)));
	((t_point*)(res_sub->content))->x = ((t_point*)(sub->content))->x;
	((t_point*)(res_sub->content))->y = ((t_point*)(sub->content))->y;
	((t_point*)(res_sub->content))->z = ((t_point*)(sub->content))->z;
	((t_point*)(res_sub->next->content))->x = ((t_point*)(sec_sub->content))->x;
	((t_point*)(res_sub->next->content))->y = ((t_point*)(sec_sub->content))->y;
	((t_point*)(res_sub->next->content))->z = ((t_point*)(sec_sub->content))->z;
	out_arr[0] = ((t_point*)(res_sub->content))->x * ((t_point*)(sub->content))->size;
	out_arr[1] = ((t_point*)(res_sub->content))->y * ((t_point*)(sub->content))->size;
	out_arr[2] = ((t_point*)(res_sub->next->content))->x * ((t_point*)(sub->content))->size;
	out_arr[3] = ((t_point*)(res_sub->next->content))->y * ((t_point*)(sub->content))->size;
	bresenham(((t_point*)(sub->content))->mlx, ((t_point*)(sub->content))->win, out_arr);
	sec_sub = sec_sub->next;
	sub = sub->next;
} 

void	img_draw(t_list *list)
{
	t_list	*sub;
	t_list	*sec_sub;
	int	out_arr[4];
	sub = list;
	while (sub->next)
	{
		out_arr[0] = ((t_point*)(sub->content))->x * ((t_point*)(sub->content))->size;
		out_arr[1] = ((t_point*)(sub->content))->y * ((t_point*)(sub->content))->size;
		out_arr[2] = ((t_point*)(sub->next->content))->x * ((t_point*)(sub->content))->size;
		out_arr[3] = ((t_point*)(sub->next->content))->y * ((t_point*)(sub->content))->size;
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
		draw_vert(sub, sec_sub);
		if (((t_point*)(sec_sub->next->content))->x_pos > ((t_point*)(sub->next->content))->x_pos)
			sec_sub = sec_sub->next;
		if (((t_point*)(sec_sub->next->content))->x_pos < ((t_point*)(sub->next->content))->x_pos)
			sub = sub->next;
		draw_vert(sub, sec_sub);
		sec_sub = sec_sub->next;
		sub = sub->next;
	}
}

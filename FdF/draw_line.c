/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:29:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 17:10:31 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2) {
    int deltaX = ft_absolute(x2 - x1);
    int deltaY = ft_absolute(y2 - y1);
    int signX = x1 < x2 ? 1 : -1;
    int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
	int error2;
    mlx_pixel_put(mlx_ptr, win_ptr, (int)x2, (int)y2, 0xFFFFFF);
    while(x1 != x2 || y1 != y2) 
   {
        mlx_pixel_put(mlx_ptr, win_ptr, (int)x1, (int)y1, 0xFFFFFF);
        error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            y1 += signY;
        }
    }
}

void	img_draw(t_list *list)
{
	t_list	*sub;
	t_list	*sec_sub;
	t_list	*res_sub;

	sub = list;
	while (sub->next)
	{	
		if (((t_point*)(sub->content))->x_pos  < ((t_point*)(sub->next->content))->x_pos)
			bresenham(((t_point*)(sub->content))->mlx, ((t_point*)(sub->content))->win, ((t_point*)(sub->content))->x, ((t_point*)(sub->content))->y, ((t_point*)(sub->next->content))->x, ((t_point*)(sub->next->content))->y);
		sub = sub->next;
	}
	sub = list;
	sec_sub = list;
	res_sub = ft_lstnew("0", sizeof(t_point));
	ft_lstadd(&res_sub, ft_lstnew("0", sizeof(t_point)));
	while (((t_point*)(sec_sub->content))->y_count == ((t_point*)(sub->content))->y_count)
			sec_sub = sec_sub->next;
	while (sec_sub->next)
	{	
		((t_point*)(res_sub->content))->x = ((t_point*)(sub->content))->x;
		((t_point*)(res_sub->content))->y = ((t_point*)(sub->content))->y;
		((t_point*)(res_sub->content))->z = ((t_point*)(sub->content))->z;
		((t_point*)(res_sub->next->content))->x = ((t_point*)(sec_sub->content))->x;
		((t_point*)(res_sub->next->content))->y = ((t_point*)(sec_sub->content))->y;
		((t_point*)(res_sub->next->content))->z = ((t_point*)(sec_sub->content))->z;
		bresenham(((t_point*)(sub->content))->mlx, ((t_point*)(sub->content))->win, ((t_point*)(res_sub->content))->x, ((t_point*)(res_sub->content))->y, ((t_point*)(res_sub->next->content))->x, ((t_point*)(res_sub->next->content))->y);
		sec_sub = sec_sub->next;
		sub = sub->next;
	}
}

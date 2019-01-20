/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:51:10 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/20 20:54:22 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_list *list)
{
	t_list	*sub;

	if (key == 53)
		exit(0);
	if (key == 69)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		((t_point*)(sub->content))->x *= 2;
		((t_point*)(sub->content))->y *= 2;
		((t_point*)(sub->content))->z *= 2;
		while (sub->next)
		{
			((t_point*)(sub->next->content))->x *= 2;
			((t_point*)(sub->next->content))->y *= 2;
			((t_point*)(sub->next->content))->z *= 2;
			sub = sub->next;
		}
		draw_img(list);
	}
	if (key == 78)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		((t_point*)(sub->content))->x /= 2;
		((t_point*)(sub->content))->y /= 2;
		((t_point*)(sub->content))->z /= 2;
		while (sub->next)
		{
			((t_point*)(sub->next->content))->x /= 2;
			((t_point*)(sub->next->content))->y /= 2;
			((t_point*)(sub->next->content))->z /= 2;
			sub = sub->next;
		}
		draw_img(list);
	}
	return (0);
}

int main(int ac, char **av)
{
	void    *mlx_ptr;
	void	*win_ptr;
	t_list	*list;
	t_list	*sub;

	
	if (ac != 2)
	{
		write(1, "usage: ./fdf file_name\n", 26);
		exit(0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 750, 750, "mlx");
	list = read_file(av[1], mlx_ptr, win_ptr);
	sub = list;
	((t_point*)(sub->content))->x *= 50;
	((t_point*)(sub->content))->y *= 50;
	((t_point*)(sub->content))->z *= 50;
	while (sub->next)
	{	
		((t_point*)(sub->next->content))->x *= 50;
		((t_point*)(sub->next->content))->y *= 50;
		((t_point*)(sub->next->content))->z *= 50;
		sub = sub->next;
	}
	ft_lstreverse(&list);
	draw_img(list);
	mlx_key_hook(win_ptr, deal_key, list);
	mlx_loop(mlx_ptr);
}

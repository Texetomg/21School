/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:51:10 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 12:22:17 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resize_img(t_list *list, double size)
{
	((t_point*)(list->content))->x *= size;
	((t_point*)(list->content))->y *= size;
	((t_point*)(list->content))->z *= size;
	while (list->next)
	{
		((t_point*)(list->next->content))->x *= size;
		((t_point*)(list->next->content))->y *= size;
		((t_point*)(list->next->content))->z *= size;
		list = list->next;
	}
}

int	deal_key(int key, t_list *list)
{
	t_list	*sub;

	if (key == 53)
		exit(0);
	if (key == 69)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		resize_img(sub, 1.1);
		draw_img(list);
	}
	if (key == 78)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		resize_img(sub, 0.9);
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
	resize_img(sub, 50);
	ft_lstreverse(&list);
	draw_img(list);
	mlx_key_hook(win_ptr, deal_key, list);
	mlx_loop(mlx_ptr);
}

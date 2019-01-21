/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:51:10 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 14:18:58 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_resize(t_list *list, double size)
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

void	img_move_x(t_list *list, int step)
{
	((t_point*)(list->content))->x += step;
	while (list->next)
	{
		((t_point*)(list->next->content))->x += step;
		list = list->next;
	}
}

void	img_move_y(t_list *list, int step)
{
	((t_point*)(list->content))->y += step;
	while (list->next)
	{
		((t_point*)(list->next->content))->y += step;
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
		img_resize(sub, 1.1);
		img_draw(list);
	}
	if (key == 78)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		img_resize(sub, 0.9);
		img_draw(list);
	}
	if (key == 123)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		img_move_x(sub, -10);
		img_draw(list);
	}
	if (key == 124)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		img_move_x(sub, 10);
		img_draw(list);
	}
	if (key == 125)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		img_move_y(sub, 10);
		img_draw(list);
	}
	if (key == 126)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		sub = list;
		img_move_y(sub, -10);
		img_draw(list);
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
	win_ptr = mlx_new_window(mlx_ptr, 850, 850, "mlx");
	list = read_file(av[1], mlx_ptr, win_ptr);
	sub = list;
	img_resize(sub, 50);
	
	ft_lstreverse(&list);
	
	add_sub_coords(&list);
	/*while (list->next)
	{
		ft_putnbr(((t_point*)(list->content))->x_pos);
		ft_putchar(' ');
		ft_putnbr(((t_point*)(list->content))->y_count);
		ft_putchar('\n');
		list = list->next;
	}*/

	img_draw(list);
	mlx_key_hook(win_ptr, deal_key, list);
	mlx_loop(mlx_ptr);
}

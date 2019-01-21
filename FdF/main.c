/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:51:10 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 20:55:14 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_resize(t_list *list, double size)
{
	((t_point*)(list->content))->size *= size;
	while (list->next)
	{
		((t_point*)(list->next->content))->size *= size;
		list = list->next;
	}
}

void	which_func(int key, t_list *sub)
{
	if (key == 69)
		img_resize(sub, 1.1);
	if (key == 78)
		img_resize(sub, 0.9);
	if (key == 123)
		img_move_x(sub, -5);
	if (key == 124)
		img_move_x(sub, 5);
	if (key == 125)
		img_move_y(sub, 5);
	if (key == 126)
		img_move_y(sub, -5);
	if (key == 91)
		img_rotate_x(sub, teta);
	if (key == 84)
		img_rotate_x(sub, -teta);
	if (key == 86)
		img_rotate_y(sub, teta);
	if (key == 88)
		img_rotate_y(sub, -teta);
	if (key == 89)
		img_rotate_z(sub, teta);
	if (key == 85)
		img_rotate_z(sub, -teta);
}

int	deal_key(int key, t_list *list)
{
	t_list	*sub;

	if (key == 53)
		exit(0);
	mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
	sub = list;
	which_func(key, sub);
	img_draw(list);
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
	if((list = read_file(av[1], mlx_ptr, win_ptr)) == 0)
		ft_putstr("bad fd");
	sub = list;
	img_resize(sub, 10);
	ft_lstreverse(&list);
	add_sub_coords(&list);
	img_draw(list);
	mlx_key_hook(win_ptr, deal_key, list);
	mlx_loop(mlx_ptr);
}

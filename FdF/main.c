/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:51:10 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/20 19:31:00 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_list *list)
{
	if (key == 53)
		exit(0);
	if (key == 69)
	{
		mlx_clear_window(((t_point*)(list->content))->mlx, ((t_point*)(list->content))->win);
		draw_img(list);
	}
	return (0);
}

int main(int ac, char **av)
{
	void    *mlx_ptr;
	void	*win_ptr;
	t_list	*list;
	if (ac != 2)
	{
		write(1, "usage: ./fdf file_name\n", 26);
		exit(0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 750, 750, "mlx");
	list = read_file(av[1], mlx_ptr, win_ptr);
	draw_img(list);
	mlx_key_hook(win_ptr, deal_key, list);
	mlx_loop(mlx_ptr);
}
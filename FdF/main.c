/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:51:10 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/23 17:25:42 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fd_error()
{
	ft_putstr("bad fd \n");
	exit(0);
}

void	list_error(t_list *list)
{
	if (LIST->x == -1)
	{
		ft_putstr("empty file \n");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_list	*list;
	t_list	*sub_list;

	if (ac != 2)
	{
		write(1, "usage: ./fdf file_name\n", 22);
		exit(0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1200, 900, "mlx");
	if ((list = read_file(av[1], mlx_ptr, win_ptr)) == 0)
		fd_error();
	sub_list = list;
	img_resize(sub_list, 10);
	ft_lstreverse(&list);
	add_sub_coords(&list);
	list_error(list);
	set_help(list);
	img_draw(list);
	mlx_key_hook(win_ptr, deal_key, list);
	mlx_loop(mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:51:10 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/17 17:17:14 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include "fdf.h"
#include <unistd.h>
#include <stdio.h>

int	deal_key(int key, void *param)
{
	param = NULL;
	if (key == 53)
		exit(0);
	return (0);
}

void bresenham_original(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr)
{
    int deltax = ft_absolute(x1 - x0);
	int error = 0;
	int deltaerr = ft_absolute(y1 - y0);
	int y = y0;
	int diry = y1 - y0;
	diry = (diry > 0)? 1: -1;
	while(x0 <= x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y, 0xFFFFFF);
		error = error + deltaerr;
		if (2 * error >= deltax)
		{
			y = y + diry;
			error = error - deltax;
		}
		x0++;
	}
}

int main(int ac, char **av)
{
	int		x0 = 0;
	int 	x1 = 500;
	int		y0 = 0;
	int		y1 = 500;
	void    *mlx_ptr;
	void	*win_ptr;
	t_list 	*strrr;
	int i;

	if (ac != 2)
	{
		write(1, "usage: ./fillit file_name\n", 26);
		exit(0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx");
	bresenham_original(x0, y0, x1, y1, mlx_ptr, win_ptr);
	strrr = read_file(av[1]);
	while (strrr)
	{
		i = 0;
		while (strrr->content)
		{
			ft_putstr((char*)strrr->content[i]);
			i++;
		}
		strrr = strrr->next;
	}
	mlx_key_hook(win_ptr, deal_key, 0);
	mlx_loop(mlx_ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:19:38 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 14:10:45 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF
#include "minilibx_macos/mlx.h"
#include "libft/libft.h"

typedef struct		s_point
{
	double x;
	double y;
	double z;
	int	y_count;
	int x_pos;
	int size;
	void *mlx;
	void *win;
}					t_point;
t_list		*read_file(char *file, void *mlx_ptr, void *win_ptr);
void		img_draw(t_list *list);
void    	add_sub_coords(t_list **list);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:19:38 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/21 21:30:21 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF
#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <math.h>
#define	teta 0.1
#define t_list_			((t_point*)(list->content))
#define t_res_sub 		((t_point*)(res_sub->content))
#define	t_res_sub_next 	((t_point*)(res_sub->next->content))
#define	t_sub 			((t_point*)(sub->content))
#define t_sub_next 		((t_point*)(sub->next->content))
#define t_sec_sub 		((t_point*)(sec_sub->content))
#define t_sec_sub_next 	((t_point*)(sec_sub->next->content))
typedef struct		s_point
{
	int	x;
	int y;
	int z;
	double size;
	double x_scale;
	double y_scale;
	double z_scale;
	int	y_count;
	int x_pos;
	void *mlx;
	void *win;
}					t_point;
t_list		*read_file(char *file, void *mlx_ptr, void *win_ptr);
void		img_draw(t_list *list);
void    	add_sub_coords(t_list **list);
void		img_move_x(t_list *list, int step);
void		img_move_y(t_list *list, int step);
void		img_rotate_x(t_list *list, double angle);
void		img_rotate_y(t_list *list, double angle);
void		img_rotate_z(t_list *list, double angle);
#endif
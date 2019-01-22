/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:19:38 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/22 20:09:52 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF
#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <math.h>
#define	TETA 0.1
#define	ALF ((t_point*)(list->content))->alf
#define	BET ((t_point*)(list->content))->bet
#define	GAM ((t_point*)(list->content))->gam
#define LIST ((t_point*)(list->content))
#define LIST_N ((t_point*)(list->next->content))
#define SUB_LIST ((t_point*)(sub_list->content))
#define SUB_LIST_N ((t_point*)(sub_list->next->content))
#define SEC_SUB ((t_point*)(sec_sub->content))
#define SEC_SUB_N ((t_point*)(sec_sub->next->content))
typedef struct		s_point
{
	int		x;
	int		y;
	int 	z;
	double 	size;
	int		x_step;
	int		y_step;	
	double	alf;
	double	bet;
	double	gam;
	int		x_curr;
	int		y_curr;
	int		z_curr;
	int		y_count;
	int		x_pos;
	void	*mlx;
	void	*win;
}					t_point;

t_list		*read_file(char *file, void *mlx_ptr, void *win_ptr);
void		img_draw(t_list *list);
void    	add_sub_coords(t_list **list);
void		img_move_x(t_list *list, int step);
void		img_move_y(t_list *list, int step);
void		img_rotate_x(t_list *list, double angle);
void		img_rotate_y(t_list *list, double angle);
void		img_rotate_z(t_list *list, double angle);
void		rotation_matrix(t_list *list, int *arr);
#endif
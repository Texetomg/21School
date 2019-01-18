/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:19:38 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/18 16:57:09 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF
#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#define x0 ((int*)(list->content))[0]
#define y0 ((int*)(list->content))[1]
#define z0 ((int*)(list->content))[2]
#define x1 ((int*)(list->next->content))[0]
#define y1 ((int*)(list->next->content))[1]
#define z1 ((int*)(list->next->content))[2]

t_list      *read_file(char *file);
void        drow_line(t_list *list, void *mlx_ptr, void *win_ptr);

#endif
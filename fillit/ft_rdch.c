/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:52:16 by thorker           #+#    #+#             */
/*   Updated: 2018/12/29 17:08:31 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char **check_block(int fd, char buff[21], char **result, int cnt_block)
{
	int		cnt_symb;
	int		cnt_diese;
	int		place[4];
	int		place_index;

	cnt_symb = -1;
	cnt_diese = 0;
	place_index = 0;
	while (++cnt_symb < 20)
	{
		if (buff[cnt_symb] == '\n')
		{
			if (cnt_symb % 5 != 4)
				return (free_result(&result, fd));
			else
				continue;
		}
		else if (buff[cnt_symb] == '#')
		{
			cnt_diese++;
			if (cnt_diese > 4)
				return (0);
			place[place_index++] = cnt_symb;
			continue;
		}
		else if (buff[cnt_symb] == '.')
			continue;
		return (free_result(*result, fd));
	}
	if (buff[cnt_symb] != '\n' || cnt_diese != 4)
		return (free_result(*result, fd));
	if (get_result(*result, place) == 0)
		return (free_result(*result, fd));
	cnt_block++;
}

char	**ft_rdch(char *file)
{
	static int	cnt_block;
	int			fd;
	char		buff[21];
	int			cnt_rd;
	char		**result;

	result = (char**)malloc(sizeof(char*));
	*result = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	cnt_block = 0;
	while ((cnt_rd = read(fd, buff, 21)) == 21)
		check_block(fd, buff, &result, cnt_block);
	if (cnt_block != 0 && cnt_rd == 0 && cnt_block < 27)
	{
		close(fd);
		return (result);
	}
	return (free_result(&result, fd));
}


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

int		check_eof(char **file)
{
	int		fd;
	char	buff[1000];
	int		index;

	index = 0;
	if ((fd = open(*file, O_RDONLY)) < 0)
		return (0);
	read(fd, buff, 1000);
	while(buff[index])
		index++;
	if (buff[index - 1] == '\n' && buff[index - 2] == '\n')
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int		check_block(char buff[21], char ***result)
{
	int cnt_s;
	int cnt_diese;
	int place_index;
	int place[4];

	cnt_s = -1;
	cnt_diese = 0;
	place_index = 0;
	while (++cnt_s < 20)
	{
		if (buff[cnt_s] == '\n' && cnt_s % 5 != 4)
			return (0);
		else if (buff[cnt_s] == '\n')
			continue;
		else if (buff[cnt_s] == '#')
		{
			if (++cnt_diese > 4)
				return (0);
			place[place_index++] = cnt_s;
			continue;
		}
		else if (buff[cnt_s] == '.')
			continue;
		return (0);
	}
	if (buff[cnt_s] != '\n' || cnt_diese != 4 || get_result(result, place) == 0)
		return (0);
	return (1);
}

char	**ft_rdch(char *file)
{
	int		cnt_block;
	int		fd;
	char	buff[21];
	int		cnt_rd;
	char	**result;

	result = (char**)malloc(sizeof(char*));
	*result = 0;
	if (!check_eof(&file) || (fd = open(file, O_RDONLY)) < 0)
		return (0);
	cnt_block = 0;
	while ((cnt_rd = read(fd, buff, 21)) >= 20)
	{
		if (check_block(buff, &result))
			cnt_block++;
		else
			return (free_result(&result, fd));
	}
	if (cnt_block != 0 && cnt_rd == 0 && cnt_block < 27)
	{
		close(fd);
		return (result);
	}
	return (free_result(&result, fd));
}

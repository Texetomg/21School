/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:52:16 by thorker           #+#    #+#             */
/*   Updated: 2019/01/13 21:08:46 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_eob(char buff[21], int cnt_rd, int cnt_diese)
{
	if (cnt_rd != 20)
		if (buff[20] != '\n')
			return (0);
	if (cnt_diese != 4)
		return (0);
	return (1);
}

int		check_block(char buff[21], char **result, int cnt_rd)
{
	int cnt_s;
	int cnt_di;
	int place_index;
	int place[4];

	cnt_s = -1;
	cnt_di = 0;
	place_index = 0;
	while (++cnt_s < 20)
	{
		if (buff[cnt_s] == '#' && cnt_s % 5 != 4)
		{
			if (++cnt_di > 4)
				return (0);
			place[place_index++] = cnt_s;
		}
		else if (buff[cnt_s] != '.' || cnt_s % 5 == 4)
			if (buff[cnt_s] != '\n' || cnt_s % 5 != 4)
				return (0);
	}
	if (check_eob(buff, cnt_rd, cnt_di) == 0 || get_result(result, place) == 0)
		return (0);
	return (1);
}

char	*ft_rdch(char *file)
{
	int		cnt_block;
	int		fd;
	char	buff[21];
	int		cnt_rd;
	char	*result;

	if ((result = (char*)malloc(sizeof(char))) == NULL)
		return (0);
	*result = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (free_result(&result, fd));
	cnt_block = 0;
	while ((cnt_rd = read(fd, buff, 21)) >= 20)
	{
		if (check_block(buff, &result, cnt_rd))
			cnt_block++;
		else
			return (free_result(&result, fd));
		if (cnt_rd == 20)
			break ;
	}
	if (cnt_block != 0 && cnt_rd == 20 && cnt_block < 27 && !close(fd))
		return (result);
	return (free_result(&result, fd));
}

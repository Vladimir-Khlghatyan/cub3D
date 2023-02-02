/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static size_t	ft_max_strlen_in_arr(char **arr)
{
	size_t	max;
	int		i;

	if (!arr)
		return (0);
	max = 0;
	i = -1;
	while (arr[++i])
		if (ft_strlen(arr[i]) > max)
			max = ft_strlen(arr[i]);
	return (max);
}

void	ft_align_arr(t_cub *c, char **arr)
{
	size_t	max;
	int		i;

	if (!arr)
		ft_error(c, "not enough resources. Try again!\n", 1);
	max = ft_max_strlen_in_arr(arr);
	i = -1;
	while (arr[++i])
	{
		while (ft_strlen(arr[i]) != max)
			arr[i] = ft_add_char_to_buf(arr[i], ' ');
	}
}

static void	ft_print_line(char c, int len)
{
	int	i;

	i = 0;
	write(1, RED, ft_strlen(RED));
	while (++i <= len)
	{
		if (i == len)
			write(1, &c, 1);
		else if (i % 2 == 0)
			write(1, " ", 1);
		else
			write(1, &c, 1);
	}
	write(1, RESET, ft_strlen(RESET));
	write(1, "\n", 1);
}

static void	ft_invalid_neighbors(t_cub *c, char **m, int y, int x)
{
	int	i;
	int	j;

	ft_error(c, "not surrounded char in the map!\n", 0);
	ft_print_line('.', x + 3);
	i = -1;
	while (m[++i])
	{
		printf("%s.%s", RED, RESET);
		j = -1;
		while (m[i][++j])
		{	
			if (ft_strchr(INSIDE_CHARS, m[i][j]) && (i == 0 || j == 0 || \
				i == y || j == x || m[i - 1][j] == ' ' || m[i + 1][j] == ' ' \
				|| m[i][j - 1] == ' ' || m[i][j + 1] == ' '))
				printf(RED);
			printf("%c%s", m[i][j], RESET);
		}
		printf("%s.%s\n", RED, RESET);
	}
	ft_print_line('.', x + 3);
	ft_arrfree(m);
	exit(1);
}

void	ft_check_inside_chars(t_cub *c, char **map)
{
	int	i;
	int	j;
	int	mh;
	int	mw;

	mh = ft_arrlen(map);
	mw = ft_strlen(map[0]);
	if (!map)
		ft_error(c, "not enough resources. Try again!\n", 1);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr(INSIDE_CHARS, map[i][j]) && \
				(i == 0 || j == 0 || i == (mh - 1) || j == (mw - 1) || \
				map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || \
				map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
				ft_invalid_neighbors(c, map, mh - 1, mw - 1);
		}
	}
}

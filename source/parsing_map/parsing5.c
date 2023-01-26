/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_set_null(char ***flr, char ***cell)
{
	if (*flr)
		(*flr) = NULL;
	if (*cell)
		(*cell) = NULL;
}

static char	**ft_get_color_subint_arr(char *map_path, char *buff, int cnt)
{
	int		fd;
	char	**flr;
	char	**cell;

	ft_set_null(&flr, &cell);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error("unable to open map!\n", 1);
	while (1)
	{
		ft_strfree(buff);
		if (cnt == 2)
			break ;
		buff = get_next_line(fd);
		if (ft_empty_or_only_spaces_str(buff) || \
			ft_begins_with_valid_xpm_name(buff))
			continue ;
		if (ft_begins_with_valid_color_name(buff) == 1)
			flr = ft_split_free(ft_color_or_xpm_path(buff, 1), ',', NULL, -1);
		else
			cell = ft_split_free(ft_color_or_xpm_path(buff, 1), ',', NULL, -1);
		cnt++;
	}
	close(fd);
	return (ft_arrtrim(ft_arrjoin(flr, cell), " "));
}

static void	ft_set_colors(t_cub *c, char **colors)
{
	c->floor_clr = ft_atoll(colors[0]) << 16 | \
				ft_atoll(colors[1]) << 8 | \
				ft_atoll(colors[2]);
	c->ceiling_clr = ft_atoll(colors[3]) << 16 | \
				ft_atoll(colors[4]) << 8 | \
				ft_atoll(colors[5]);
	ft_arrfree(colors);
}

void	ft_get_color_values(char *map_path, t_cub *c)
{
	char	**colors;
	int		i;

	ft_check_comma_count(map_path, NULL, 0);
	ft_check_allowed_chars(map_path, NULL, 0);
	colors = ft_get_color_subint_arr(map_path, NULL, 0);
	if (!colors)
		ft_error("can't get color codes from map!\n", 1);
	i = -1;
	while (colors[++i])
	{
		if (ft_check_long_long_limits(colors[i]) == 0 || \
			ft_atoll(colors[i]) < 0 || ft_atoll(colors[i]) > 255)
		{
			ft_arrfree(colors);
			ft_error("color code out of range [0:255] in map!\n", 1);
		}
	}
	ft_set_colors(c, colors);
}

void	ft_chek_nsew_char_cnt(char **map)
{
	int	i;
	int	j;
	int	cnt;

	if (!map)
		return ;
	cnt = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (ft_strchr(DIRECTIONS, map[i][j]))
				cnt++;
	}
	if (cnt != 1)
	{
		ft_arrfree(map);
		ft_error("count of 'NSEW' chars in map must be 1!\n", 1);
	}
}

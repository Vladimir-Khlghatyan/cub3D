/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	**ft_add_str_to_arr(char **arr, char *str)
{
	int		i;
	char	**new_arr;

	if (!str)
		return (arr);
	new_arr = (char **)malloc(sizeof(char *) * (ft_arrlen(arr) + 2));
	if (!new_arr)
		return (ft_arrfree(arr));
	i = 0;
	if (arr)
	{
		i = -1;
		while (arr[++i])
			new_arr[i] = arr[i];
	}
	new_arr[i] = ft_strdup(str);
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}

static char	**ft_remove_first_str_from_arr(char **arr)
{
	int		i;
	char	**new_arr;

	if (!arr || ft_arrlen(arr) == 1)
		return (ft_arrfree(arr));
	new_arr = (char **)malloc(sizeof(char *) * ft_arrlen(arr));
	if (!new_arr)
		return (ft_arrfree(arr));
	i = 0;
	while (arr[++i])
		new_arr[i - 1] = arr[i];
	new_arr[i - 1] = NULL;
	free(arr[0]);
	free(arr);
	return (new_arr);
}

static char	**ft_read_map(char *map_path, char *buff)
{
	char	**map;
	int		cnt;
	int		fd;

	map = NULL;
	cnt = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error("unable to open map!\n", 1);
	while (1)
	{
		ft_strfree(buff);
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (cnt < 6 && ft_empty_or_only_spaces_str(buff))
			continue ;
		if (ft_begins_with_valid_xpm_name(buff) || \
			ft_begins_with_valid_color_name(buff))
			cnt++;
		if (cnt >= 6)
			map = ft_add_str_to_arr(map, buff);
	}
	close(fd);
	return (ft_remove_first_str_from_arr(map));
}

static char	**ft_empty_strs_in_arr(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	while (ft_empty_or_only_spaces_str(arr[0]) == 1)
		arr = ft_remove_first_str_from_arr(arr);
	if (arr)
	{
		i = -1;
		while (arr[++i])
		{
			if (ft_empty_or_only_spaces_str(arr[i]) == 1)
			{
				ft_arrfree(arr);
				ft_error("empty line in map!\n", 1);
			}
		}
	}
	return (arr);
}

char	**ft_get_map(char *map_path, t_cub *c)
{
	char	**map;
	int		i;

	ft_valid_xpm_names(map_path, NULL, 0, 0);
	ft_valid_color_names(map_path, NULL, 0, 0);
	ft_xpm_path_check(map_path, c);
	ft_get_color_values(map_path, c);
	map = ft_read_map(map_path, NULL);
	if (!map)
		ft_error("unable to get map!\n", 1);
	i = -1;
	while (map[++i])
	{	
		if (!ft_strset(map[i], POSIBLE_CHARS))
		{
			ft_arrfree(map);
			ft_error("invalid character in map!\n", 1);
		}
	}
	map = ft_empty_strs_in_arr(map);
	ft_chek_nsew_char_cnt(map);
	ft_align_arr(map);
	ft_check_inside_chars(map);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_comma_count(char *str)
{
	int	cnt;
	int	i;

	if (!str)
		return (0);
	cnt = 0;
	i = -1;
	while (str[++i])
		if (str[i] == ',')
			cnt++;
	return (cnt);
}

static int	ft_allowed_chars(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',' && str[i] != ' ')
			return (0);
	return (1);
}

void	ft_check_comma_count(t_cub *c, char *map_path, char *b, int cnt)
{
	int		fd;
	char	*tmp;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error(c, "unable to open map!\n", 1);
	while (true)
	{
		ft_strfree(b);
		if (cnt == 2)
			break ;
		b = get_next_line(fd);
		if (ft_empty_or_only_spaces_str(b) || \
			ft_begins_with_valid_xpm_name(b))
			continue ;
		tmp = ft_color_or_xpm_path(b, 1);
		if (ft_comma_count(tmp) != 2)
		{
			ft_strfree2(b, tmp);
			ft_error(c, "invalid count of comma in map (in clr code)!\n", 1);
		}
		free(tmp);
		cnt++;
	}
	close(fd);
}

void	ft_check_allowed_chars(t_cub *c, char *map_path, char *b, int cnt)
{
	int		fd;
	char	*tmp;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error(c, "unable to open map!\n", 1);
	while (true)
	{
		ft_strfree(b);
		if (cnt == 2)
			break ;
		b = get_next_line(fd);
		if (ft_empty_or_only_spaces_str(b) || \
			ft_begins_with_valid_xpm_name(b))
			continue ;
		tmp = ft_color_or_xpm_path(b, 1);
		if (ft_allowed_chars(tmp) == 0)
		{
			ft_strfree2(b, tmp);
			ft_error(c, "invalid color code in map!\n", 1);
		}
		free(tmp);
		cnt++;
	}
	close(fd);
}

int	ft_check_long_long_limits(char *str)
{
	char		*new_str;
	int			i;
	int			start;

	if (!str)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (!str[i])
		return (1);
	new_str = ft_lltoa(ft_atoll(str));
	start = 0;
	if (ft_sign(str) == -1)
		start = 1;
	if (!ft_strcmp(str + i, new_str + start))
	{
		free(new_str);
		return (1);
	}
	free(new_str);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_color_or_xpm_path(char *str, int flag)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == ' ')
		i++;
	i += flag;
	while (str[i] == ' ')
		i++;
	return (ft_substr(str, i, ft_strlen(str + i)));
}

static char	**ft_get_xpm_paths_arr(char *map_path, char *buff, int cnt)
{
	int			fd;
	char		**xpm_paths;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error("unable to open map!\n", 1);
	xpm_paths = (char **)malloc(sizeof(char *) * (4 + 1));
	if (!xpm_paths)
		return (NULL);
	xpm_paths[4] = NULL;
	while (1)
	{
		ft_strfree(buff);
		if (cnt == 4)
			break ;
		buff = get_next_line(fd);
		if (ft_empty_or_only_spaces_str(buff))
			continue ;
		xpm_paths[ft_begins_with_valid_xpm_name(buff) - 1] = \
								ft_color_or_xpm_path(buff, 2);
		cnt++;
	}
	close(fd);
	return (xpm_paths);
}

void	ft_xpm_path_check(char *map_path, t_cub *c)
{
	char	**xpm_paths;

	xpm_paths = ft_get_xpm_paths_arr(map_path, NULL, 0);
	if (!xpm_paths)
		ft_error("unable to check xpm pats!\n", 1);
	c->xpm_no = mlx_xpm_file_to_image(c->mlx, xpm_paths[0], &c->wxpm[0], \
																&c->hxpm[0]);
	c->xpm_so = mlx_xpm_file_to_image(c->mlx, xpm_paths[1], &c->wxpm[1], \
																&c->hxpm[1]);
	c->xpm_we = mlx_xpm_file_to_image(c->mlx, xpm_paths[2], &c->wxpm[2], \
																&c->hxpm[2]);
	c->xpm_ea = mlx_xpm_file_to_image(c->mlx, xpm_paths[3], &c->wxpm[3], \
																&c->hxpm[3]);
	ft_arrfree(xpm_paths);
	if (!c->xpm_no || !c->xpm_so || !c->xpm_we || !c->xpm_ea)
		ft_error("invalid xmp paths in map!\n", 1);
}

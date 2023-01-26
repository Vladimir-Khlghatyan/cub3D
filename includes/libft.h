/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:38:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/10/31 00:56:55 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdint.h>

char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_arrlen(char **arr);
char		**ft_arrjoin(char **arr1, char **arr2);
char		**ft_arrtrim(char **arr, char *set);
char		**ft_split_free(char *s, char c, char *tmp, int i);
int			ft_sign(char *str);
long long	ft_atoll(char *str);
char		*ft_lltoa(long long n);
int			ft_strcmp(char *s1, char *s2);
int			ft_strset(char *str, char *set);

#endif

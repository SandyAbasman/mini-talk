/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandy <asandy@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:54:59 by asandy            #+#    #+#             */
/*   Updated: 2022/02/07 22:37:23 by asandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	startindex(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0' && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int	endindex(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j] != '\0' && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
			break ;
		i--;
	}
	return (i);
}

static int	strtrimlen(char const *s1, char const *set)
{
	int	diff;

	diff = endindex(s1, set) - startindex(s1, set);
	if (diff < 0)
		return (0);
	return (diff + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*result;
	int		len;
	int		start_index;

	len = strtrimlen(s1, set);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result)
	{
		start_index = startindex(s1, set);
		i = 0;
		while (i < len)
		{
			result[i] = s1[start_index + i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

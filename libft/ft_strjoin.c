/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandy <asandy@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:54:59 by asandy            #+#    #+#             */
/*   Updated: 2022/02/07 22:36:31 by asandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_size;
	int		total_size;

	s1_size = ft_strlen(s1);
	total_size = s1_size + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * total_size);
	if (result)
	{
		ft_strlcpy(result, s1, s1_size + 1);
		ft_strlcat(result, s2, total_size);
	}	
	return (result);
}

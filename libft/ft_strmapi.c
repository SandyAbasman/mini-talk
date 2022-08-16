/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandy <asandy@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:41:04 by asandy            #+#    #+#             */
/*   Updated: 2022/02/08 06:43:07 by asandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				n;
	char			*ptr;

	if (!s || !f)
		return (NULL);
	n = 0;
	ptr = malloc (sizeof(char) *(ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (s[n])
	{
		ptr[n] = (f)(n, s[n]);
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}

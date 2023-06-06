/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:14:08 by rsiqueir          #+#    #+#             */
/*   Updated: 2021/05/20 21:01:40 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	char	*dest2;

	dest2 = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	dest = dest2;
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*dest;

	dest = malloc(ft_strlen(s1) + 1);
	if (!(dest))
		return (NULL);
	if (dest == 0)
		return (0);
	ft_strcpy(dest, s1);
	return (dest);
}

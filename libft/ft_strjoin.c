/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:26:27 by rsiqueir          #+#    #+#             */
/*   Updated: 2021/05/20 20:42:14 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*pointer;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	pointer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(pointer))
		return (NULL);
	while (s1[a])
	{
		pointer[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		pointer[a] = s2[b];
		b++;
		a++;
	}
	pointer[a] = '\0';
	return (pointer);
}

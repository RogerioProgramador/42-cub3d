/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogeriorslf <rogeriorslf@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:59:12 by rsiqueir          #+#    #+#             */
/*   Updated: 2021/05/26 22:55:55 by rogeriorslf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pointer;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	pointer = malloc(ft_strlen(s) + 1);
	if (!pointer)
		return (NULL);
	pointer[ft_strlen(s)] = 0;
	while (s[i])
	{
		pointer[i] = f(i, s[i]);
		i++;
	}
	return (pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogeriorslf <rogeriorslf@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:19:54 by rsiqueir          #+#    #+#             */
/*   Updated: 2021/05/28 13:00:46 by rogeriorslf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim(char *s1, char *set)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (set[++i])
		if (*s1 == set[i])
			j++;
	if (j != 0)
		return (ft_trim(++s1, set));
	return (s1);
}

char	*ft_mirt(char *s1, char *set, char const *end)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (s1 == end)
		return (s1);
	while (set[++i])
		if (*s1 == set[i])
			j++;
	if (j != 0)
		return (ft_mirt(--s1, set, end));
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		trim_strlen;
	char	*pointer;
	void	*trim_pointer;
	void	*mirt_pointer;

	if (s1 == NULL || set == NULL)
		return (NULL);
	trim_pointer = ft_trim((char *)s1, (char *)set);
	mirt_pointer = ft_mirt(((char *)s1 + ft_strlen(s1) - 1), (char *)set, s1);
	trim_strlen = mirt_pointer - trim_pointer + 1;
	if (trim_strlen < 0)
	{
		pointer = ft_calloc(sizeof(char), 1);
		if (!pointer)
			return (NULL);
		pointer[0] = '\0';
		return (pointer);
	}
	pointer = ft_calloc((trim_strlen + 1), sizeof(char));
	if (!pointer)
		return (NULL);
	ft_memccpy(pointer, trim_pointer, 1, trim_strlen);
	return (pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogerio <rogerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 00:22:53 by rogeriorslf       #+#    #+#             */
/*   Updated: 2021/09/11 17:47:41 by rogerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	a;

	a = 0;
	pointer = malloc(count * size);
	if (pointer == NULL)
		return (NULL);
	while (a < count * size)
	{
		((unsigned char *)pointer)[a] = '\0';
		a++;
	}
	return (pointer);
}

char	*verifier(int fd, char **line)
{
	char	*bag;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (NULL);
	bag = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bag)
		return (NULL);
	return (bag);
}

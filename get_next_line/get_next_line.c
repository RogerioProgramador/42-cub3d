/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogerio <rogerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 00:21:59 by rogeriorslf       #+#    #+#             */
/*   Updated: 2021/09/13 08:02:15 by rogerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	check_wrong_order(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*taking_delivery(char *s1, char *s2)
{
	int		count[2];
	char	*pointer;

	count[0] = 0;
	count[1] = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	pointer = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!pointer)
		return (NULL);
	while (s1 && s1[count[0]])
	{
		pointer[count[0]] = s1[count[0]];
		count[0]++;
	}
	while (s2 && s2[count[1]])
	{
		pointer[count[0]] = s2[count[1]];
		count[1]++;
		count[0]++;
	}
	free (s1);
	return (pointer);
}

char	*leftovers(char *s)
{
	char	*pointer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	pointer = (char *)ft_calloc(sizeof(char), ((ft_strlen(s) - i) + 1));
	if (!pointer)
		return (0);
	i++;
	while (s[i])
		pointer[j++] = s[i++];
	free(s);
	return (pointer);
}

char	*delivery(char *pointer)
{
	int		i;
	char	*return_p;

	i = 0;
	if (!pointer)
		return (0);
	while (pointer[i] && pointer[i] != '\n')
		i++;
	return_p = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!return_p)
		return (0);
	i = -1;
	while (pointer[++i] && pointer[i] != '\n')
		return_p[i] = pointer[i];
	return (return_p);
}

int	get_next_line(int fd, char **line)
{
	int				i;
	char			*bag;
	static char		*motoboy;

	bag = verifier(fd, line);
	if (!bag)
		return (-1);
	i = 1;
	while (!check_wrong_order(motoboy, '\n') && i != 0)
	{
		i = read(fd, bag, BUFFER_SIZE);
		if (i == -1)
		{
			free(bag);
			return (-1);
		}
		bag[i] = '\0';
		motoboy = taking_delivery(motoboy, bag);
	}
	free(bag);
	*line = delivery(motoboy);
	motoboy = leftovers(motoboy);
	if (i == 0)
		return (0);
	return (1);
}

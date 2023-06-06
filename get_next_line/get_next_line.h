/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogerio <rogerio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 00:23:24 by rogeriorslf       #+#    #+#             */
/*   Updated: 2021/09/13 14:13:12 by rogerio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>

int			check_wrong_order(char *s, char c);

int			get_next_line(int fd, char **line);

char		*verifier(int fd, char **line);

char		*taking_delivery(char *s1, char *s2);

char		*ft_strndup(char *s1, char c);

void		*ft_calloc(size_t count, size_t size);

size_t		ft_strlen(const char *s);
#endif

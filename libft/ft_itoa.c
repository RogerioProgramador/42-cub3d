/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogeriorslf <rogeriorslf@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:08:21 by rsiqueir          #+#    #+#             */
/*   Updated: 2021/06/08 21:48:25 by rogeriorslf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_length(int nb)
{
	if (nb < 0)
		nb = nb * -1;
	if (nb <= 9)
		return (1);
	else
		return (int_length(nb / 10) + 1);
}

char	*nb_to_string(char *stringnb, int n, int cases, char sign)
{
	if (sign == '-')
	{
		stringnb[0] = '-';
		cases++;
	}
	while ((cases - 1) >= 0)
	{
		stringnb[cases - 1] = (n % 10) + '0';
		n = n / 10;
		cases--;
		if (cases == 1 && sign == '-')
			cases--;
	}
	return (stringnb);
}

char	*min_number(void)
{
	char	*stringnb;

	stringnb = ft_calloc(sizeof(char), 12);
	if (!stringnb)
		return (NULL);
	ft_strlcpy(stringnb, "-2147483648", 12);
	return (stringnb);
}

char	*ft_itoa(int n)
{
	int		cases;
	char	*stringnb;

	cases = int_length(n);
	if (n < 0)
	{
		if (n == -2147483648)
			return (min_number());
		n *= -1;
		stringnb = ft_calloc(cases + 2, sizeof(char));
		if (!stringnb)
			return (NULL);
		stringnb = nb_to_string(stringnb, n, cases, '-');
	}
	else
	{
		stringnb = ft_calloc(cases + 1, sizeof(char));
		if (!stringnb)
			return (NULL);
		stringnb = nb_to_string(stringnb, n, cases, '+');
	}
	return (stringnb);
}

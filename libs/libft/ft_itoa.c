/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:42:10 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/11 11:45:40 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	cal_bytes(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static char	*assign_chars(char *str, size_t bytes_count, int n)
{
	size_t	i;
	int		digit;
	char	c;
	size_t	index_limit;

	i = bytes_count - 1;
	index_limit = 0;
	if (n < 0)
	{
		n *= -1;
		index_limit = 1;
		str[0] = '-';
	}
	while (i > index_limit)
	{
		digit = n % 10;
		c = digit + 48;
		str[i - 1] = c;
		n = (n - digit) / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	bytes_count;
	char	*ascii_str;

	if (n == 0)
	{
		ascii_str = ft_strdup("0");
		if (!ascii_str)
			return (NULL);
		return (ascii_str);
	}
	else if (n == -2147483648)
	{
		ascii_str = ft_strdup("-2147483648");
		if (!ascii_str)
			return (NULL);
		return (ascii_str);
	}
	bytes_count = 1;
	if (n < 0)
		++bytes_count;
	bytes_count += cal_bytes(n);
	ascii_str = (char *)ft_calloc(bytes_count, sizeof(char));
	if (ascii_str == NULL)
		return (NULL);
	return (assign_chars(ascii_str, bytes_count, n));
}

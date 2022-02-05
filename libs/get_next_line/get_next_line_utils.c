/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:57 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/28 21:34:25 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/* -------------------------------------------------------------------------- */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* -------------------------------------------------------------------------- */

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*myptr;

	i = 0;
	myptr = (char *)s;
	while (i++ < n)
		*(myptr++) = 0;
}

/* -------------------------------------------------------------------------- */

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*dest;
	size_t	i;

	src_len = ft_strlen(src);
	dest = (char *)malloc((src_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, (src_len + 1) * sizeof(char));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/* -------------------------------------------------------------------------- */

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*output_str;
	size_t	output_i;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	output_str = (char *) malloc((i + 1) * sizeof(char));
	if (!output_str)
		return (0);
	ft_bzero(output_str, (i + 1) * sizeof(char));
	if (!i)
		return (output_str);
	i = 0;
	output_i = 0;
	while (s1[i])
		output_str[output_i++] = s1[i++];
	i = 0;
	while (s2[i])
		output_str[output_i++] = s2[i++];
	return (output_str);
}

/* -------------------------------------------------------------------------- */

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	my_c;

	i = 0;
	my_c = (char) c;
	while (s[i])
	{
		if (s[i] == my_c)
			return ((char *)&s[i]);
		i++;
	}
	if (my_c == 0 && s[i] == my_c)
		return ((char *)&s[i]);
	return (0);
}

/* -------------------------------------------------------------------------- */

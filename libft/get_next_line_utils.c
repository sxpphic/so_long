/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:27:40 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/27 10:36:10 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_gnl_strjoin(char const *s1, char const	*s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_gnl_strdup(const char	*s1)
{
	char	*string;
	size_t	i;

	i = 0;
	string = (char *)malloc(sizeof(*string) * (ft_gnl_strlen(s1) + 1));
	if (string == NULL)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_gnl_substr(char const	*s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_gnl_strlen(s) < len)
		len = ft_gnl_strlen(s);
	str = (char *)malloc(len * sizeof(*str) + 1);
	if (str == NULL)
		return (NULL);
	if (start >= ft_gnl_strlen(s))
	{
		str[i] = '\0';
		return (str);
	}
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

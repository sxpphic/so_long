/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:51:10 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/09 10:01:59 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nwords(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
		while (*s == c && *s)
			s++;
	}
	return (i);
}

static int	ft_start(char const *s, char c)
{
	int	i;

	i = 0;
	if (*s == c)
	{
		while (*s == c)
		{
			s++;
			i++;
		}
		return (i);
	}
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	while (*s == c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

static char	*ft_help(const char *s, int start, int *len, char c)
{
	int		slen;
	char	*str;

	slen = *len;
	slen = ft_len(&s[start], c);
	len = &slen;
	str = ft_substr(s, start, slen);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		start;
	int		len;

	start = 0;
	len = 0;
	i = 0;
	if (!s)
		return (0);
	array = ft_calloc(1, sizeof(char *) * (ft_nwords(s, c) + 1));
	if (array == NULL)
		return (0);
	array[0] = 0;
	if (s[0] == 0)
		return (array);
	if (s[start] != c)
		array[i++] = ft_help(s, start, &len, c);
	while (i <= ft_nwords(s, c) - 1)
	{
		start = start + ft_start(&s[start], c);
		array[i++] = ft_help(s, start, &len, c);
	}
	return (array);
}

/*
#include <stdio.h>
int main(void)
{
	int		i;
	char	**fvck;
	i = 0;
	printf("test nword\n");
	printf("%i\n", ft_nwords("", '-'));
	printf("%i\n", ft_nwords("aaaaaa----bbbbbbbbb----ccc--d------e----", '-'));
	printf("%i\n", ft_nwords("------aaaaaaa----bbbbbb----ccccc--d--e", '-'));

	fvck = ft_split("------aaaaaaaaa----bbbbbbbb----cccc--d------e", '-');
	while (i <= 5)
		printf("%s\n", fvck[i++]);
	i = 0;
	fvck = ft_split("------aaaaaaaaa----bbbbbb----ccccccc--d------e", '-');
	while (i <= 5)
		printf("%s\n", fvck[i++]);
	i = 0;
	fvck = ft_split("aaaaaaaaa----bbbbbbbbb----cccccccccc-----e", '-');
	while (i <= 5)
		printf("%s\n", fvck[i++]);
	i = 0;
	printf("testando\n");
	fvck = ft_split("      split       this for   me  !       ", ' ');
	while (i <= 6)
		printf("%s\n", fvck[i++]);
	return (0);
}*/

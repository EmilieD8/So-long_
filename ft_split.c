/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:00:35 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/25 11:12:07 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*checksub(void)
{
	char	*substr;

	substr = malloc (1 * sizeof(char));
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*substr;

	if (!s)
		return (0);
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		return (checksub());
	substr = (char *) malloc (sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	countsubstr(char const *s, char c)
{
	int		words;
	size_t	index;

	index = 0;
	words = 0;
	while (s[index] != '\0')
	{
		if ((s[index] != c && s[index + 1] == c)
			|| (s[index] != c && s[index + 1] == '\0'))
			words++;
		index++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	index;
	int		i;
	int		start;

	index = 0;
	i = 0;
	start = 0;
	arr = malloc(sizeof (char *) * (countsubstr(s, c) + 1));
	if (!arr || !s)
		return (NULL);
	while (index < ft_strlen(s))
	{
		if (s[index] == c && s[index + 1] != c)
			start = index + 1;
		if ((s[index] != c && s[index + 1] == c)
			|| (s[index] != c && s[index + 1] == '\0'))
		{
			arr[i] = ft_substr(s, start, (index + 1) - start);
			i++;
		}
		index++;
	}
	arr[i] = 0;
	return (arr);
}

/* int	main(void)
{
	char *s = "lorem ipsum doendisse";
	char	c;
	int		i;
	char **str;
	i = 0;
	c = ' ';
	str = ft_split(s, c);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:26:04 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/25 11:10:27 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	lengthcombine(char const *s1, char const *s2)
{
	size_t		l1;
	size_t		l2;
	size_t		l3;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	l3 = l1 + l2;
	return (l3);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		l3;
	char	*s3;
	int		sindex;
	size_t	bindex;

	l3 = lengthcombine(s1, s2);
	s3 = (char *)malloc(sizeof(char) * (l3 + 1));
	if (!s3)
		return (NULL);
	sindex = 0;
	bindex = 0;
	while (bindex < ft_strlen(s1))
		s3[bindex++] = s1[sindex++];
	sindex = 0;
	while (bindex < l3)
		s3[bindex++] = s2[sindex++];
	s3[bindex] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (s3);
}

/*int	main(void)
{
	char	*s1 = "je veux ecrire";
	char	*s2 = " une jolie histoire.";
	printf("%s",ft_strjoin(s1,s2));
}*/

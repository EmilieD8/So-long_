/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:08:14 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/24 16:36:33 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	searchn(char *tmp)
{
	int	index;

	index = 0;
	if (!tmp)
		return (0);
	while (tmp[index] != '\0')
	{
		if (tmp[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*memcpyb(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (n > 0)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dest);
}

char	*join_buffer_tmp(char *tmp, char *buffer)
{
	char	*newtmp;
	int		lengthbuffer;
	int		lengthtmp;

	if (!tmp)
	{
		tmp = malloc(sizeof(char));
		if (tmp == NULL)
			return (NULL);
		*tmp = '\0';
	}
	if (*buffer == '\0')
		return (tmp);
	lengthtmp = ft_strlen(tmp);
	lengthbuffer = ft_strlen(buffer);
	newtmp = malloc(sizeof(char) * (lengthbuffer + lengthtmp) + 1);
	if (!newtmp)
		return (NULL);
	memcpyb(newtmp, tmp, lengthtmp);
	memcpyb(newtmp + lengthtmp, buffer, lengthbuffer + 1);
	free(tmp);
	return (newtmp);
}

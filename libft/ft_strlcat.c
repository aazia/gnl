/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:16:49 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/20 14:44:48 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s1[i] != 0 && i <= size)
		i++;
	k = i;
	if (size != 0 && k < size)
	{
		while (s2[j] && j < size - k - 1)
			s1[i++] = s2[j++];
	}
	if (i < size)
	{
		s1[i] = '\0';
		return (ft_strlen(s2) + k);
	}
	return (size + ft_strlen(s2));
}

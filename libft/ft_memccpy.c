/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:15:05 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/13 18:24:33 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	unsigned char		k;
	size_t				i;

	i = 0;
	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	k = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == k)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

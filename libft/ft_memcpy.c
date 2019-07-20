/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:15:05 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/20 14:48:16 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*og;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	og = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		og[i] = s[i];
		i++;
	}
	return (dst);
}

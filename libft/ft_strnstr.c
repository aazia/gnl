/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:00:19 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/22 16:47:59 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[i] == '\0' || needle == 0)
		return ((char *)haystack);
	while (haystack[j] && (j + ft_strlen(needle)) <= len)
	{
		while (needle[i] == haystack[j + i] && needle[i] && haystack[j + i])
		{
			i++;
		}
		if (needle[i] == '\0')
			return ((char *)(haystack + j));
		j++;
		i = 0;
	}
	return (NULL);
}

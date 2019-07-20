/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:46:17 by azkeever          #+#    #+#             */
/*   Updated: 2018/11/20 14:39:38 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (!(s))
		return (NULL);
	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	len += start;
	while (start < len && s[start] != '\0')
		str[i++] = s[start++];
	if (start != len)
		return (NULL);
	str[i] = '\0';
	return (str);
}
